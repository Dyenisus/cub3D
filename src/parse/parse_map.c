/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:14:03 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/06 22:51:55 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*build_grid_row(char *line, int width)
{
	char	*row;
	int		i;

	row = ft_calloc((width + 1), sizeof(char));
	if (!row)
	{
		return (NULL);
	}
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		row[i] = line[i];
		i++;
	}
	while (i < width)
	{
		row[i] = ' ';
		i++;
	}
	return (row);
}

static int	build_grid(t_parser *parser, int map_start)
{
	char	*line;
	int		i;
	int		width;

	parser->map.grid = ft_calloc((parser->map.height + 1), sizeof(char *));
	if (!parser->map.grid)
	{
		return (print_error("Malloc failed"));
	}
	width = parser->map.width;
	i = 0;
	while (i < parser->map.height)
	{
		line = parser->lines[map_start + i];
		parser->map.grid[i] = build_grid_row(line, width);
		if (!parser->map.grid[i])
		{
			return (print_error("Malloc failed"));
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	check_results(t_parser *parser, int map_start)
{
	if (map_start == -1)
	{
		return (print_error("Missing map"));
	}
	if (!parser->has_north_texture
		|| !parser->has_south_texture
		|| !parser->has_west_texture
		|| !parser->has_east_texture)
	{
		return (print_error("Missing texture identifier"));
	}
	if (!parser->has_floor_color || !parser->has_ceiling_color)
	{
		return (print_error("Missing color identifier"));
	}
	return (EXIT_SUCCESS);
}

int	parse_map(t_parser *parser)
{
	int	i;
	int	map_start;
	int	map_ended;

	i = 0;
	map_start = -1;
	map_ended = 0;
	while (i < parser->line_count)
	{
		if (scan_line(parser, i, &map_start, &map_ended) == EXIT_FAILURE)
		{
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (check_results(parser, map_start) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	return (build_grid(parser, map_start));
}
