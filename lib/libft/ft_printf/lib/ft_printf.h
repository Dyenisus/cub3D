/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:19:50 by yektasoytur       #+#    #+#             */
/*   Updated: 2025/10/11 15:32:09 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *s, ...);
int	printf_putchar(char c);
int	printf_putchar_arg(va_list args);
int	printf_putnbr_arg(va_list args, char *base);
int	printf_strlen(const char *s);
int	printf_putstr_arg(va_list args);
int	printf_putunsigned(va_list args, char *base);
int	printf_putadress(va_list args, char *base);

#endif