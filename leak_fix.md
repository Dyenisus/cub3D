# Leak Fix Notes

## Problem

There was a leak in the `read_ret < 0` path in `get_next_line.c`.

When `read()` failed inside `gnl_main_loop`, the code freed `ret` but did not free the static buffer used by `get_next_line`. That left the static allocation alive on the error return path.

## Changes Made

### 1. Added central cleanup for error path

In `get_next_line.c`, a helper was added:

```c
static char	*gnl_free_all(char **buf, char *ret)
{
	free(ret);
	free(*buf);
	*buf = NULL;
	return (NULL);
}
```

The `read_ret < 0` branch now returns through this helper, so both `ret` and the static buffer are released.

### 2. Fixed static buffer lifetime at EOF

Another helper was added:

```c
static char	*gnl_eof_return(char **buf, char *ret)
{
	free(*buf);
	*buf = NULL;
	return (ret);
}
```

On EOF, the previous version only set `*buf = '\0'`. That kept the allocation alive and also caused a later reallocation without freeing the old buffer first. The EOF path now frees the static buffer and resets it to `NULL`.

### 3. Stopped reallocating on empty buffer state

This condition:

```c
if (!buf || !*buf)
```

was changed to:

```c
if (!buf)
```

Because after EOF the buffer is now freed and reset to `NULL`, there is no need to allocate again just because the buffer contents are empty.

### 4. Fixed the local test driver

`get_main.c` was updated to:

- free every line returned by `get_next_line`
- close the opened file descriptor

This was necessary so `valgrind` output reflects the library behavior instead of caller-side leaks.

## Verification

### Compile

Compiled successfully with:

```sh
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c get_main.c -o gnl_test
```

### Valgrind

Checked with:

```sh
valgrind --leak-check=full --show-leak-kinds=all \
	--track-fds=yes --errors-for-leak-kinds=all ./gnl_test
```

Result:

- `in use at exit: 0 bytes in 0 blocks`
- `All heap blocks were freed -- no leaks are possible`
- `ERROR SUMMARY: 0 errors from 0 contexts`

### Extra test coverage

A dedicated test file, `gnl_valgrind_test.c`, was added to drain `get_next_line` correctly and free all returned lines.

This was run under `valgrind` for:

- empty file
- one line without trailing newline
- one line with trailing newline
- multiple lines including empty lines
- invalid fd case

All cases finished with:

- `0 bytes in 0 blocks`
- `0 errors from 0 contexts`

## Note About File Descriptors

`valgrind` reporting:

```text
FILE DESCRIPTORS: 3 open (3 std) at exit.
```

is normal. Those are:

- `stdin`
- `stdout`
- `stderr`

They are not leaks. A real file descriptor leak would appear as an extra open descriptor such as fd `3` or higher.
