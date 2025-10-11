/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:23:08 by yesoytur          #+#    #+#             */
/*   Updated: 2025/10/10 19:49:47 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_len(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_chr(const char *s, int c)
{
	const unsigned char	*n_s;
	size_t				n;

	if (!s)
		return (NULL);
	n = gnl_len(s) + 1;
	n_s = (const unsigned char *)s;
	while (n--)
	{
		if (*n_s == (unsigned char)c)
			return ((char *)n_s);
		n_s++;
	}
	return (NULL);
}

void	*gnl_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == src || !n)
		return (dest);
	if (dest < src)
	{
		d = (unsigned char *)dest;
		s = (const unsigned char *)src;
		while (n--)
			*d++ = *s++;
		return (dest);
	}
	else
	{
		d = (unsigned char *)dest + n;
		s = (const unsigned char *)src + n;
		while (n--)
			*--d = *--s;
		return (dest);
	}
}

int	gnl_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1;
	char	*tmp;

	if (!size2)
		return (1);
	if (!*s1)
		size1 = 0;
	else
		size1 = gnl_len(*s1);
	tmp = malloc(size2 + size1 +1);
	if (!tmp)
		return (0);
	gnl_memmove(tmp, *s1, size1);
	gnl_memmove(tmp + size1, s2, size2);
	tmp[size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	gnl_append_str(char **s1, char *s2)
{
	return (gnl_append_mem(s1, s2, gnl_len(s2)));
}
