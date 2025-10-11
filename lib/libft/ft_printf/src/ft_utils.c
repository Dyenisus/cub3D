/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:20:48 by yektasoytur       #+#    #+#             */
/*   Updated: 2025/10/11 15:59:19 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	printf_putchar_arg(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (printf_putchar(c));
}

int	printf_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*printf_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*cpy_s1;

	if (!s1)
		return (NULL);
	len = printf_strlen(s1);
	cpy_s1 = (char *)malloc((len + 1) * sizeof(char));
	if (!cpy_s1)
		return (NULL);
	i = 0;
	while (s1[i] && i < len - 1)
	{
		cpy_s1[i] = s1[i];
		i++;
	}
	cpy_s1[i] = '\0';
	return (cpy_s1);
}

int	printf_putstr_arg(va_list args)
{
	int		count;
	int		i;
	char	*s;

	s = printf_strdup(va_arg(args, char *));
	if (!s)
	{
		write(1, "(nill)", 6);
		return (6);
	}
	count = 0;
	i = 0;
	while (s[i])
	{
		count += printf_putchar(s[i]);
		i++;
	}
	free(s);
	return (count);
}
