/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 22:40:02 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/14 13:52:26 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_walkable(t_game *game, double x, double y)
{
	char	cell;

	if (x < 0.0 || y < 0.0 || x >= game->map->width || y >= game->map->height)
	{
		return (0);
	}
	cell = game->map->grid[(int)y][(int)x];
	{
		return (cell == '0' || cell == 'N' || cell == 'S'
			|| cell == 'E' || cell == 'W');
	}
}

static void	move_camera(t_game *game, double move_x, double move_y)
{
	double	next_x;
	double	next_y;

	next_x = game->camera.x + move_x;
	next_y = game->camera.y + move_y;
	if (is_walkable(game, next_x, game->camera.y))
	{
		game->camera.x = next_x;
	}
	if (is_walkable(game, game->camera.x, next_y))
	{
		game->camera.y = next_y;
	}
}

static void	rotate_camera(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->camera.dir_x;
	old_plane_x = game->camera.plane_x;
	game->camera.dir_x = game->camera.dir_x * cos(angle)
			- game->camera.dir_y * sin(angle);
	game->camera.dir_y = old_dir_x * sin(angle)
			+ game->camera.dir_y * cos(angle);
	game->camera.plane_x = game->camera.plane_x * cos(angle)
			- game->camera.plane_y * sin(angle);
	game->camera.plane_y = old_plane_x * sin(angle)
			+ game->camera.plane_y * cos(angle);
}

static void	update_camera(t_game *game, double delta_time)
{
	double	move_x;
	double	move_y;
	double	length;

	move_x = (game->camera.dir_x * (game->input.move_forward
			- game->input.move_backward))
			+ (game->camera.dir_y * (game->input.move_left
			- game->input.move_right));
	move_y = (game->camera.dir_y * (game->input.move_forward
			- game->input.move_backward))
			+ (-game->camera.dir_x * (game->input.move_left
			- game->input.move_right));
	length = sqrt((move_x * move_x) + (move_y * move_y));
	if (length > 0.0)
	{
		move_camera(game, (move_x / length) * MOVE_SPEED * delta_time,
			(move_y / length) * MOVE_SPEED * delta_time);
	}
	if (game->input.turn_left)
	{
		rotate_camera(game, -ROT_SPEED * delta_time);
	}
	if (game->input.turn_right)
		rotate_camera(game, ROT_SPEED * delta_time);
}

int	game_loop(t_game *game)
{
	struct timeval	now;
	long			current_time;
	double			delta_time;

	gettimeofday(&now, NULL);
	current_time = (now.tv_sec * 1000L) + (now.tv_usec / 1000L);
	if (game->last_frame_time == 0)
	{
		game->last_frame_time = current_time;
	}
	delta_time = (current_time - game->last_frame_time) / 1000.0;
	game->last_frame_time = current_time;
	if (delta_time > 0.0)
	{
		update_camera(game, delta_time);
	}
	render_frame(game);
	return (0);
}
