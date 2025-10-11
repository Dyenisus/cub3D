/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:52:47 by yesoytur          #+#    #+#             */
/*   Updated: 2025/10/07 20:39:39 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_len(long nbr)
{
	size_t	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	to_ascii(char *s, long nbr, size_t len, int sign)
{
	if (sign)
		*s = '-';
	s[len + sign] = '\0';
	while (len--)
	{
		s[len + sign] = (nbr % 10) + '0';
		nbr /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nbr;
	int		sign;
	size_t	len;

	nbr = (long)n;
	sign = (nbr < 0);
	if (sign)
		nbr = -nbr;
	len = nbr_len(nbr);
	s = malloc((len + sign + 1) * sizeof(char));
	if (!s)
		return (NULL);
	to_ascii(s, nbr, len, sign);
	return (s);
}
