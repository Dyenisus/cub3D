/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:09:46 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/14 21:47:59 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	handle_mouse_press(int button, int x, int y, t_game *game)
{
	(void)y;
	if (button == Button1)
	{
		game->input.mouse_enabled = !game->input.mouse_enabled;
		game->input.last_mouse_x = x;
		game->input.has_last_mouse_x = 1;
	}
	return (0);
}

int	handle_mouse_move(int x, int y, t_game *game)
{
	int	delta_x;

	(void)y;
	if (!game->input.mouse_enabled)
	{
		return (0);
	}
	if (!game->input.has_last_mouse_x)
	{
		game->input.last_mouse_x = x;
		game->input.has_last_mouse_x = 1;
		return (0);
	}
	delta_x = x - game->input.last_mouse_x;
	game->input.last_mouse_x = x;
	if (delta_x != 0)
	{
		rotate_camera(game, delta_x * MOUSE_SENSITIVITY);
	}
	return (0);
}
