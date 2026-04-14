/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:35:13 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/14 21:45:34 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static double	ray_delta(double ray_dir)
{
	if (ray_dir == 0.0)
	{
		return (1e30);
	}
	return (fabs(1.0 / ray_dir));
}

static void	init_ray_step(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0.0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->camera.x - ray->map_x)
					* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->camera.x)
					* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0.0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->camera.y - ray->map_y)
					* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->camera.y)
					* ray->delta_dist_y;
	}
}

void	init_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2.0 * x / (double)WIN_WIDTH - 1.0;
	ray->ray_dir_x = game->camera.dir_x
			+ game->camera.plane_x * ray->camera_x;
	ray->ray_dir_y = game->camera.dir_y
			+ game->camera.plane_y * ray->camera_x;
	ray->map_x = (int)game->camera.x;
	ray->map_y = (int)game->camera.y;
	ray->delta_dist_x = ray_delta(ray->ray_dir_x);
	ray->delta_dist_y = ray_delta(ray->ray_dir_y);
	init_ray_step(game, ray);
}

static void	step_ray(t_game *game, t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

void	cast_ray(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		step_ray(game, ray);
		if (ray->map_x < 0 || ray->map_y < 0
				|| ray->map_x >= game->map->width
				|| ray->map_y >= game->map->height)
			hit = 1;
		else if (game->map->grid[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->camera.x
						+ (1 - ray->step_x) / 2.0) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->camera.y
						+ (1 - ray->step_y) / 2.0) / ray->ray_dir_y;
	if (ray->perp_wall_dist < 0.0001)
			ray->perp_wall_dist = 0.0001;
}
