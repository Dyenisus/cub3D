/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:59:41 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/09 21:12:16 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include "../../include/cub3d.h"

static void	init_img(t_img *img)
{
	img->ptr = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
}

void	init_game_struct(t_game *game, t_map *map)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = map;
	init_img(&game->frame);
	init_img(&game->textures.north);
	init_img(&game->textures.south);
	init_img(&game->textures.west);
	init_img(&game->textures.east);
	game->camera.x = 0.0;
	game->camera.y = 0.0;
	game->camera.dir_x = 0.0;
	game->camera.dir_y = 0.0;
	game->camera.plane_x = 0.0;
	game->camera.plane_y = 0.0;
}

int	init_frame(t_game *game)
{
	game->frame.ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->frame.ptr)
	{
		return (print_error("Failed to create frame image"));
	}
	game->frame.width = WIN_WIDTH;
	game->frame.height = WIN_HEIGHT;
	game->frame.addr = mlx_get_data_addr(game->frame.ptr, &game->frame.bpp,
								&game->frame.line_len, &game->frame.endian);
	if (!game->frame.addr)
	{
		return (print_error("Failed to get frame data"));
	}
	return (EXIT_SUCCESS);
}
