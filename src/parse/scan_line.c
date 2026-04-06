/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 22:36:23 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/06 21:01:44 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	parse_map_section(t_parser *parser, char *line, int *map_ended)
{
	if (is_empty_line(line))
	{
		*map_ended = 1;
	}
	else if (*map_ended)
	{
		return (print_error("Map must be last"));
	}
	else if (!is_map_line(line))
	{
		return (print_error("Invalid map line"));
	}
	else
	{
		update_map_size(parser, line);
	}
	return (EXIT_SUCCESS);
}

static int	parse_config(t_parser *parser, char *line, int i, int *map_start)
{
	int	ret;

	if (is_empty_line(line))
	{
		return (EXIT_SUCCESS);
	}
	if (is_map_line(line))
	{
		*map_start = i;
		update_map_size(parser, line);
		return (EXIT_SUCCESS);
	}
	ret = parse_element_line(parser, line);
	if (ret == PARSER_NO_MATCH)
	{
		return (print_error("Invalid element"));
	}
	return (ret);
}

static char	*trim_newline(char *line)
{
	return (ft_strtrim(line, "\n"));
}

int	scan_line(t_parser *parser, int i, int *map_start, int *map_ended)
{
	int		ret;
	char	*line;

	line = trim_newline(parser->lines[i]);
	if (!line)
	{
		return (print_error("Malloc failed"));
	}
	if (*map_start == -1)
	{
		ret = parse_config(parser, line, i, map_start);
	}
	else
	{
		ret = parse_map_section(parser, line, map_ended);
	}
	free(line);
	return (ret);
}
