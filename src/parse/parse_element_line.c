/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 23:05:44 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/06 21:01:20 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	store_color(t_color *color, int *flag, char *value)
{
	while (*value == ' ' || *value == '\t')
	{
		value++;
	}
	if (*flag)
	{
		return (print_error("Duplicate color identifier"));
	}
	if (!*value)
	{
		return (print_error("Missing color value"));
	}
	if (parse_color_value(value, color) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	*flag = 1;
	return (EXIT_SUCCESS);
}

static int	store_texture(char **dst, int *flag, char *value)
{
	while (*value == ' ' || *value == '\t')
	{
		value++;
	}
	if (*flag)
	{
		return (print_error("Duplicate texture identifier"));
	}
	if (!*value)
	{
		return (print_error("Missing texture path"));
	}
	*dst = ft_strdup(value);
	if (!*dst)
	{
		return (print_error("Malloc failed"));
	}
	*flag = 1;
	return (EXIT_SUCCESS);
}

static int	parse_texture_line(char *line, t_parser *parse)
{
	if (!ft_strncmp(line, "NO", 2) && (line[2] == ' ' || line[2] == '\t'))
	{
		return (store_texture(&parse->map.north.path,
						&parse->has_north_texture, line + 2));
	}
	if (!ft_strncmp(line, "SO", 2) && (line[2] == ' ' || line[2] == '\t'))
	{
		return (store_texture(&parse->map.south.path,
						&parse->has_south_texture, line + 2));
	}
	if (!ft_strncmp(line, "WE", 2) && (line[2] == ' ' || line[2] == '\t'))
	{
		return (store_texture(&parse->map.west.path,
						&parse->has_west_texture, line + 2));
	}
	if (!ft_strncmp(line, "EA", 2) && (line[2] == ' ' || line[2] == '\t'))
	{
		return (store_texture(&parse->map.east.path,
						&parse->has_east_texture, line + 2));
	}
	return (PARSER_NO_MATCH);
}

static int	parse_f_or_c_color(char *line, t_parser *parser)
{
	if (line[0] == 'F' && (line[1] == ' ' || line[1] == '\t'))
	{
		return (store_color(&parser->map.floor_color,
						&parser->has_floor_color, line + 1));
	}
	if (line[0] == 'C' && (line[1] == ' ' || line[1] == '\t'))
	{
		return (store_color(&parser->map.ceiling_color,
						&parser->has_ceiling_color, line + 1));
	}
	return (PARSER_NO_MATCH);
}

int	parse_element_line(t_parser *parser, char *line)
{
	int	ret;

	ret = parse_texture_line(line, parser);
	if (ret != PARSER_NO_MATCH)
	{
		return (ret);
	}
	ret = parse_f_or_c_color(line, parser);
	if (ret != PARSER_NO_MATCH)
	{
		return (ret);
	}
	return (PARSER_NO_MATCH);
}
