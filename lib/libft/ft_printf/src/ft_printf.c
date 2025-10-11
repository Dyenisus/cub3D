/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:20:53 by yektasoytur       #+#    #+#             */
/*   Updated: 2025/10/11 15:35:40 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_type(char ftype, va_list args)
{
	int	count;

	count = 0;
	if (ftype == '\0')
		return (count);
	if (ftype == '%')
		count += printf_putchar('%');
	else if (ftype == 'c')
		count += printf_putchar_arg(args);
	else if (ftype == 's')
		count += printf_putstr_arg(args);
	else if (ftype == 'd' || ftype == 'i')
		count += printf_putnbr_arg(args, "0123456789");
	else if (ftype == 'u')
		count += printf_putunsigned(args, "0123456789");
	else if (ftype == 'x')
		count += printf_putunsigned(args, "0123456789abcdef");
	else if (ftype == 'X')
		count += printf_putunsigned(args, "0123456789ABCDEF");
	else if (ftype == 'p')
		count += printf_putadress(args, "0123456789abcdef");
	else
		count += printf_putchar(ftype);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += ft_format_type(s[i], args);
		}
		else
			count += printf_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
