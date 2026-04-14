/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:56:39 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/14 22:41:51 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	has_xpm_extension(char *path)
{
	char	*name;
	int		len;

	name = ft_strrchr(path, '/');
	if (name)
	{
		name++;
	}
	else
	{
		name = path;
	}
	len = ft_strlen(name);
	if (len < 5)
		return (0);
	return (ft_strncmp(name + len - 4, ".xpm", 4) == 0);
}

static int	is_not_readable_texture_file(char *path)
{
	int		fd;
	int		bytes;
	char	c;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		return (1);
	}
	bytes = read(fd, &c, 1);
	close(fd);
	if (bytes <= 0)
	{
		return (1);
	}
	return (0);
}

static int	is_invalid_texture_path(char *path)
{
	if (!path)
	{
		return (1);
	}
	if (!has_xpm_extension(path))
	{
		return (1);
	}
	if (access(path, R_OK) != 0)
	{
		return (1);
	}
	if (is_not_readable_texture_file(path))
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
