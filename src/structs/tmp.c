/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:53:24 by yesoytur          #+#    #+#             */
/*   Updated: 2025/12/08 11:44:57 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_tmp(t_tmp *tmp)
{
	init_texture(&tmp->tex);
	tmp->f_str = NULL;
	tmp->c_str = NULL;
	tmp->map = NULL;
	tmp->width = 0;
	tmp->height = 0;
	tmp->player_x = -1;
	tmp->player_y = -1;
	tmp->player_dir = 'N';
}
