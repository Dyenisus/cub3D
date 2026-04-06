/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:14:03 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/05 22:37:39 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
