/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:46:34 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/06 10:08:46 by yesoytur         ###   ########.fr       */
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

void	initial_validations(int ac, char **av);
int		print_err(char *msg);
void	print_use_ext(char *msg);
void	print_err_ext(char *msg);
void	free_2d(char **arr);
void	free_tex(t_tex *tex);
void	free_tmp(t_tmp *tmp);
void	free_tmp_allocs(t_tmp *tmp);
void	init_tex(t_tex *tex);
void	init_tmp(t_tmp *tmp);
char	**retrive_lines(char *map_path);
int		is_skipspace(char *line, int *index);

t_map	*tmp_to_map(t_tmp *tmp);
t_map	*parse_map_file(char *map_path);

#endif
