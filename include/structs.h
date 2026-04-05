/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:05:54 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/04 22:21:52 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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

#endif
