/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:22:45 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/03 13:20:56 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	init_tex(t_tex *tex)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tex->tex[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		tex->f_color[i] = -1;
		tex->c_color[i] = -1;
		i++;
	}
}

void	init_tmp(t_tmp *tmp)
{
	init_tex(&tmp->tex);
	tmp->f_str = NULL;
	tmp->c_str = NULL;
	tmp->map = NULL;
	tmp->width = 0;
	tmp->height = 0;
	tmp->player_x = -1;
	tmp->player_y = -1;
	tmp->player_dir = 'N';
}

t_map	*tmp_to_map(t_tmp *tmp)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->textures = malloc(sizeof(t_tex));
	if (!map->textures)
	{
		free(map);
		return (NULL);
	}
	*(map->textures) = tmp->tex;
	map->map = tmp->map;
	map->width = tmp->width;
	map->height = tmp->height;
	map->player_x = tmp->player_x + 0.5;
	map->player_y = tmp->player_y + 0.5;
	map->player_dir = tmp->player_dir;
	return (map);
}
