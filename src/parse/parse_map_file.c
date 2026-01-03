/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:53:19 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/03 13:56:00 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	parent_parse(char **lines, t_tmp *tmp);

t_map	*parse_map_file(char *map_path)
{
	t_map		*map;
	t_tmp		tmp;
	char		**lines;

	init_tmp(&tmp);
	lines = retrive_lines(map_path);
	if (!lines || !*lines)
	{
		print_err("Invalid map file");
		free_2d(lines);
		return (NULL);
	}
	if (parent_parse(lines, &tmp))
	{
		free_tmp(&tmp);
		free_2d(lines);
		return (NULL);
	}
	map = tmp_to_map(&tmp);
	free_tmp_allocs(&tmp);
	free_2d(lines);
	return (map);
}

static int	parent_parse(char **lines, t_tmp *tmp)
{
	if (!parse_header(lines, tmp))
	{
		return (print_err("Invalid header"));
	}
	if (!parse_map(lines, tmp))
	{
		return (print_err("Invalid map content"));
	}
	return (0);
}

// Parse all the map file (header and map)