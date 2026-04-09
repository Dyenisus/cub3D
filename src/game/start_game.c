/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 20:50:54 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/09 22:32:23 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		return (print_error("Failed to initialize mlx"));
	}
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
	{
		return (print_error("Failed to create window"));
	}
	return (EXIT_SUCCESS);
}

int	start_game(t_map *map)
{
	t_game	game;

	if (!map)
		return (EXIT_FAILURE);
	init_game_struct(&game, map);
	if (init_window(&game) == EXIT_FAILURE)
	{
		cleanup_game(&game);
		return (EXIT_FAILURE);
	}
	if (init_frame(&game) == EXIT_FAILURE)
	{
		cleanup_game(&game);
		return (EXIT_FAILURE);
	}
	if (init_textures(&game) == EXIT_FAILURE)
	{
		cleanup_game(&game);
		return (EXIT_FAILURE);
	}
	init_camera(&game);
	register_hooks(&game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (EXIT_SUCCESS);
}
