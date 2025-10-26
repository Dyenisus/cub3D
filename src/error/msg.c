/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:05:06 by yesoytur          #+#    #+#             */
/*   Updated: 2025/10/26 18:20:04 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	print_err(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	return (1);
}

void	print_use_ext(char *msg)
{
	print_err(msg);
	ft_printf("Usage: './cub3D map/map_name.cub'\n");
	exit(EXIT_FAILURE);
}

void	print_err_ext(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}
