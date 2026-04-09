/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 22:32:35 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/09 22:39:02 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	set_key_state(int keysym, t_game *game, int state)
{
	if (keysym == XK_w || keysym == XK_W)
		game->input.move_forward = state;
	else if (keysym == XK_s || keysym == XK_S)
		game->input.move_backward = state;
	else if (keysym == XK_a || keysym == XK_A)
		game->input.move_left = state;
	else if (keysym == XK_d || keysym == XK_D)
		game->input.move_right = state;
	else if (keysym == XK_Left)
		game->input.turn_left = state;
	else if (keysym == XK_Right)
		game->input.turn_right = state;
	else
		return (0);
	return (1);
}

static int	handle_key_press(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(game->mlx);
		return (0);
	}
	set_key_state(keysym, game, 1);
	return (0);
}

static int	handle_key_release(int keysym, t_game *game)
{
	set_key_state(keysym, game, 0);
	return (0);
}

static int	handle_window_close(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	register_hooks(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, &handle_key_press, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, &handle_key_release, game);
	mlx_hook(game->win, ButtonPress, ButtonPressMask, &handle_mouse_press, game);
	mlx_hook(game->win, MotionNotify, PointerMotionMask, &handle_mouse_move, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask,
	&handle_window_close, game);
	mlx_loop_hook(game->mlx, &game_loop, game);
	return (EXIT_SUCCESS);
}
