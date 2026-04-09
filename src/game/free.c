/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 20:17:30 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/09 20:22:54 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	destroy_img(void *mlx, t_img *img)
{
	if (img->ptr)
	{
		mlx_destroy_image(mlx, img->ptr);
	}
}

void	cleanup_game(t_game *game)
{
	if (game->mlx)
	{
		destroy_img(game->mlx, &game->frame);
		destroy_img(game->mlx, &game->textures.north);
		destroy_img(game->mlx, &game->textures.south);
		destroy_img(game->mlx, &game->textures.west);
		destroy_img(game->mlx, &game->textures.east);
		if (game->win)
		{
			mlx_destroy_window(game->mlx, game->win);
		}
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
}

void	free_map(t_map *map)
{
	if (!map)
	{
		return ;
	}
	free_2d_array(map->grid);
	free(map->north.path);
	free(map->south.path);
	free(map->west.path);
	free(map->east.path);
	free(map);
}
