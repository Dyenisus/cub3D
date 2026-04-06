/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:06:07 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/06 20:58:33 by yesoytur         ###   ########.fr       */
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


#endif
