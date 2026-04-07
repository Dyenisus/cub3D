/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:56:39 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/07 22:14:44 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_invalid_texture_path(char *path)
{
	if (!path || access(path, R_OK) != 0)
	{
		return (1);
	}
	return (0);
}

int	validate_textures(t_map *map)
{
	if (is_invalid_texture_path(map->north.path))
	{
		return (print_error("Invalid north texture path"));
	}
	if (is_invalid_texture_path(map->south.path))
	{
		return (print_error("Invalid south texture path"));
	}
	if (is_invalid_texture_path(map->west.path))
	{
		return (print_error("Invalid west texture path"));
	}
	if (is_invalid_texture_path(map->east.path))
	{
		return (print_error("Invalid east texture path"));
	}
	return (EXIT_SUCCESS);
}
