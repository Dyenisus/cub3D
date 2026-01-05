/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:00:19 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/05 12:20:20 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H


typedef enum e_tex_id
{
	Unknown = -1,
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	F = 4,
	C = 5,
}	t_tex_id;


typedef struct s_tex
{
	char	*tex[4];
	int		f_color[3];
	int		c_color[3];
}	t_tex;


typedef struct s_tmp
{
	t_tex	tex;
	char	*f_str;
	char	*c_str;

	char	**map;
	int		width;
	int		height;

	int		player_x;
	int		player_y;
	char	player_dir;
}	t_tmp;

typedef struct s_map
{
	t_tex		*textures;
	char		**map;
	int			width;
	int			height;

	double		player_x;
	double		player_y;
	char		player_dir;
}	t_map;

#endif