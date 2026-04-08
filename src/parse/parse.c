/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:17:54 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/08 19:56:35 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_map	*parse_fail(t_parser *parser)
{
	free_parser(parser);
	return (NULL);
}

static t_map *build_map_from_parser(t_parser *parser)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		print_error("Malloc failed");
		return (NULL);
	}
	*map = parser->map;
	parser->map.grid = NULL;
	parser->map.north.path = NULL;
	parser->map.south.path = NULL;
	parser->map.west.path = NULL;
	parser->map.east.path = NULL;
	return (map);
}

t_map	*parse(char *path)
{
	t_parser	parser;
	t_map		*map;

	init_parser(&parser, path);
	if (read_and_store(&parser) == EXIT_FAILURE)
	{
		return (parse_fail(&parser));
	}
	if (parse_map(&parser) == EXIT_FAILURE)
	{
		return (parse_fail(&parser));
	}
	if (validate(&parser) == EXIT_FAILURE)
	{
		return (parse_fail(&parser));
	}
	map = build_map_from_parser(&parser);
	if (!map)
	{
		return (parse_fail(&parser));
	}
	free_parser(&parser);
	return (map);
}
