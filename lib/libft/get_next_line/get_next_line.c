/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:22:54 by yesoytur          #+#    #+#             */
/*   Updated: 2025/10/10 19:50:21 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_main_loop(int fd, char **buf, char *ret)
{
	char		*nl;
	ssize_t		read_ret;

	while (1)
	{
		nl = gnl_chr(*buf, '\n');
		if (!nl)
		{
			if (**buf && !gnl_append_str(&ret, *buf))
				return (NULL);
			read_ret = read(fd, *buf, BUFFER_SIZE);
			if (read_ret < 0)
				return (free(ret), NULL);
			if (read_ret == 0)
				return (**buf = '\0', ret);
			(*buf)[read_ret] = '\0';
		}
		else
		{
			if (!gnl_append_mem(&ret, *buf, (size_t)(nl - *buf) + 1))
				return (free(ret), NULL);
			gnl_memmove(*buf, nl + 1, gnl_len(nl + 1) + 1);
			return (ret);
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf || !*buf)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		*buf = '\0';
	}
	ret = NULL;
	return (gnl_main_loop(fd, &buf, ret));
}
