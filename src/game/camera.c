/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 21:04:53 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/09 21:11:33 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	set_camera_north(t_game *game)
{
	game->camera.dir_x = 0.0;
	game->camera.dir_y = -1.0;
	game->camera.plane_x = 0.66;
	game->camera.plane_y = 0.0;
}

static void	set_camera_south(t_game *game)
{
	game->camera.dir_x = 0.0;
	game->camera.dir_y = 1.0;
	game->camera.plane_x = -0.66;
	game->camera.plane_y = 0.0;
}

static void	set_camera_west(t_game *game)
{
	game->camera.dir_x = -1.0;
	game->camera.dir_y = 0.0;
	game->camera.plane_x = 0.0;
	game->camera.plane_y = -0.66;
}

static void	set_camera_east(t_game *game)
{
	game->camera.dir_x = 1.0;
	game->camera.dir_y = 0.0;
	game->camera.plane_x = 0.0;
	game->camera.plane_y = 0.66;
}

void	init_camera(t_game *game)
{
	game->camera.x = game->map->player.x;
	game->camera.y = game->map->player.y;
	if (game->map->player.dir == 'N')
	{
		set_camera_north(game);
	}
	else if (game->map->player.dir == 'S')
	{
		set_camera_south(game);
	}
	else if (game->map->player.dir == 'W')
	{
		set_camera_west(game);
	}
	else
	{
		set_camera_east(game);
	}
}
