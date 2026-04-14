/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:44:22 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/14 13:50:46 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_texture_pixel(t_img *img, int x, int y)
{
	char	*src;

	if (x < 0)
	{
		x = 0;
	}	
	if (y < 0)
	{
		y = 0;
	}
	if (x >= img->width)
	{
		x = img->width - 1;
	}
	if (y >= img->height)
	{
		y = img->height - 1;
	}
	src = img->addr + (y * img->line_len) + (x * (img->bpp / 8));
	return (*(unsigned int *)src);
}

static t_img	*get_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0 && ray->ray_dir_x > 0.0)
	{
		return (&game->textures.west);
	}
	if (ray->side == 0 && ray->ray_dir_x < 0.0)
	{
		return (&game->textures.east);
	}
	if (ray->side == 1 && ray->ray_dir_y > 0.0)
	{
		return (&game->textures.north);
	}
	return (&game->textures.south);
}

static void	init_draw(t_game *game, t_ray *ray, t_draw *draw)
{
	draw->texture = get_wall_texture(game, ray);
	draw->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	draw->draw_start = -draw->line_height / 2 + WIN_HEIGHT / 2;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end = draw->line_height / 2 + WIN_HEIGHT / 2;
	if (draw->draw_end >= WIN_HEIGHT)
		draw->draw_end = WIN_HEIGHT - 1;
	if (ray->side == 0)
		draw->wall_x = game->camera.y
				+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		draw->wall_x = game->camera.x
				+ ray->perp_wall_dist * ray->ray_dir_x;
	draw->wall_x -= floor(draw->wall_x);
	draw->tex_x = (int)(draw->wall_x * (double)draw->texture->width);
	if (ray->side == 0 && ray->ray_dir_x > 0.0)
		draw->tex_x = draw->texture->width - draw->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0.0)
		draw->tex_x = draw->texture->width - draw->tex_x - 1;
	draw->step = 1.0 * draw->texture->height / draw->line_height;
	draw->tex_pos = (draw->draw_start - WIN_HEIGHT / 2
			+ draw->line_height / 2) * draw->step;
}

void	draw_wall_column(t_game *game, t_ray *ray, int x)
{
	t_draw	draw;
	int		y;
	int		color;

	init_draw(game, ray, &draw);
	y = draw.draw_start;
	while (y <= draw.draw_end)
	{
		draw.tex_y = (int)draw.tex_pos;
		draw.tex_pos += draw.step;
		color = get_texture_pixel(draw.texture, draw.tex_x, draw.tex_y);
		put_img_pixel(&game->frame, x, y, color);
		y++;
	}
}
