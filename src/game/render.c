/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:28:24 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/14 13:33:04 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	put_img_pixel(t_img *img, int x, int y, int color)
{
	char    *dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
	{
		return ;
	}
	dst = img->addr + (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
			{
				put_img_pixel(&game->frame, x, y,	
					game->map->ceiling_color.value);
			}
			else
			{
				put_img_pixel(&game->frame, x, y,
					game->map->floor_color.value);
			}
			x++;
		}
		y++;
	}
}

void	render_frame(t_game *game)
{
	t_ray	ray;
	int		x;

	draw_background(game);
	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(game, &ray, x);
		cast_ray(game, &ray);
		draw_wall_column(game, &ray, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->frame.ptr, 0, 0);
}
