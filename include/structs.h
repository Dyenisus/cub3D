/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:05:54 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/09 22:30:33 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define MOVE_SPEED 3.0
# define ROT_SPEED 2.0
# define MOUSE_SENSITIVITY 0.002

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
	int		value;
}	t_color;

typedef struct s_player
{
	double	x;
	double	y;
	char	dir;
}	t_player;

typedef struct	s_texture
{
	char	*path;
}	t_texture;

typedef struct s_map
{
	char		*file_path;
	char		**grid;
	int			width;
	int			height;
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	t_color		floor_color;
	t_color		ceiling_color;
	t_player	player;
}	t_map;

typedef struct s_parser
{
	t_map	map;
	char	**lines;
	int		line_count;
	int		capacity;
	int		has_north_texture;
	int		has_south_texture;
	int		has_west_texture;
	int		has_east_texture;
	int		has_floor_color;
	int		has_ceiling_color;
	int		player_count;
}	t_parser;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_camera
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_camera;

typedef struct s_tex
{
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
}	t_tex;

typedef struct s_input
{
	int	move_forward;
	int	move_backward;
	int	move_left;
	int	move_right;
	int	turn_left;
	int	turn_right;
	int	mouse_enabled;
	int	has_last_mouse_x;
	int	last_mouse_x;
}	t_input;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_img		frame;
	t_tex		textures;
	t_camera	camera;
	t_input		input;
	long		last_frame_time;
}	t_game;

#endif
