/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:06:07 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/09 21:35:03 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "include.h"

# define PARSER_NO_MATCH -1

int		print_error(char *message);
int		is_invalid_input(int ac, char *path);
t_map	*parse(char *path);
void	init_parser(t_parser *parser, char *path);
int		read_and_store(t_parser *parser);
void	free_2d_array(char	**arr);
void	free_parser(t_parser *parser);
int		is_empty_line(char *line);
int		is_map_line(char *line);
void	update_map_size(t_parser *parser, char *line);
int		parse_element_line(t_parser *parser, char *line);
int		has_only_digits(char *line);
int		parse_color_value(char *value, t_color *color);
int		scan_line(t_parser *parser, int i, int *map_start, int *map_ended);
int		parse_map(t_parser *parser);
int		validate_textures(t_map *map);
int		validate_cells(t_parser *parser);
int		validate_map_closed(t_parser *parser);
int		validate(t_parser *parser);
void	cleanup_game(t_game *game);
void	free_map(t_map *map);
void	init_game_struct(t_game *game, t_map *map);
int		init_frame(t_game *game);
void	init_camera(t_game *game);
int		init_textures(t_game *game);
int   	start_game(t_map *map);

#endif
