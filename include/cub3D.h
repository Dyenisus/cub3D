/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:46:34 by yesoytur          #+#    #+#             */
/*   Updated: 2025/12/08 11:40:10 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/time.h>
# include <math.h>
# include <errno.h>
# include "structs.h"
# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/minilibx-linux/mlx_int.h"

void	initial_checks(int ac, char **av);
int		print_err(char *msg);
void	print_use_ext(char *msg);
void	print_err_ext(char *msg);
void	init_texture(t_texture *tex);
void	init_tmp(t_tmp *tmp);

#endif