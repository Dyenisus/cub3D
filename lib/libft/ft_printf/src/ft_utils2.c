/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:13:18 by yektasoytur       #+#    #+#             */
/*   Updated: 2025/10/11 15:19:02 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_number_based(unsigned long nbr, char *base, int count)
{
	unsigned int	base_length;

	base_length = printf_strlen(base);
	if (nbr >= base_length)
		count += ft_number_based(nbr / base_length, base, count);
	printf_putchar(base[nbr % base_length]);
	return (count + 1);
}

int	printf_putnbr_arg(va_list args, char *base)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = va_arg(args, int);
	if (nbr < 0)
	{
		nbr = -nbr;
		count += printf_putchar('-');
	}
	count += ft_number_based(nbr, base, count);
	return (count);
}

int	printf_putunsigned(va_list args, char *base)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	nbr = va_arg(args, unsigned int);
	count += ft_number_based(nbr, base, count);
	return (count);
}

int	printf_putadress(va_list args, char *base)
{
	int				count;
	void			*check;
	unsigned long	nbr;

	check = va_arg(args, void *);
	if (!check)
	{
		write(1, "0x0", 3);
		return (3);
	}
	nbr = (unsigned long)check;
	write(1, "0x", 2);
	count = 2;
	count += ft_number_based(nbr, base, count);
	return (count);
}
