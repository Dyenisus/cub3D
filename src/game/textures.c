/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 21:05:02 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/09 21:06:05 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	load_texture(t_game *game, t_img *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(game->mlx, path, &img->width, &img->height);
	if (!img->ptr)
	{
		return (print_error("Failed to load texture"));	
	}
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_len,
							&img->endian);
	if (!img->addr)
	{
		return (print_error("Failed to get texture data"));
	}	
	return (EXIT_SUCCESS);
}

int	init_textures(t_game *game)
{
	if (load_texture(game, &game->textures.north, game->map->north.path)
			== EXIT_FAILURE)
	{		
		return (EXIT_FAILURE);
	}
	if (load_texture(game, &game->textures.south, game->map->south.path)
			== EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	if (load_texture(game, &game->textures.west, game->map->west.path)
			== EXIT_FAILURE)
	{	
		return (EXIT_FAILURE);
	}
	if (load_texture(game, &game->textures.east, game->map->east.path)
			== EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
