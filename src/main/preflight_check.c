/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preflight_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 19:21:45 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/14 22:13:08 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	extension_is_not_cub(char *path)
{
	char	*name;
	int		len;

	if (!path)
		return (EXIT_FAILURE);
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
	{
		return (EXIT_FAILURE);
	}
	if (ft_strncmp(name + len - 4, ".cub", 4) != 0)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	is_invalid_input(int ac, char *path)
{
	if (ac != 2)
	{
		return (print_error("Usage: ./cub3D <path/to/map.cub>"));
	}
	if (extension_is_not_cub(path))
	{
		return (print_error("Invalid map extension"));
	}
	return (EXIT_SUCCESS);
}
