/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:17:54 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/05 17:04:55 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_map	*parse_fail(t_parser *parser)
{
	free_parser(parser);
	return (NULL);
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
