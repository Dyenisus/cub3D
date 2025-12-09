/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:53:19 by yesoytur          #+#    #+#             */
/*   Updated: 2025/12/09 11:29:21 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_map	*parse_map_file(char *map_path)
{
	t_tmp		tmp;
	t_map		*map;
	char		**lines;

	init_tmp(&tmp);
	lines = retrive_lines(map_path);
	if (!lines || !*lines)
	{
		print_err("Invalid Map");
		free_2d(lines);
		return (NULL);
	}
	parse_header(tmp);
	parse_map(tmp);
}
