/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:57:43 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/07 22:40:55 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	free_grid(char **grid)
{
	free_2d_array(grid);
}

static char **copy_grid(t_map *map)
{
	char	**copy;
	int		i;

	copy = ft_calloc((map->height + 1), sizeof(char *));
	if (!copy)
	{
		return (NULL);
	}
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->grid[i]);
		if (!copy[i])
		{
			free_grid(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

static int	flood_fill(char **grid, t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
	{
		return (EXIT_FAILURE);
	}
	if (grid[y][x] == ' ')
	{
		return (EXIT_FAILURE);
	}
	if (grid[y][x] == '1' || grid[y][x] == 'V')
	{
		return (EXIT_SUCCESS);
	}
	grid[y][x] = 'V';
	if (flood_fill(grid, map, x + 1, y) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (flood_fill(grid, map, x - 1, y) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (flood_fill(grid, map, x, y + 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (flood_fill(grid, map, x, y - 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	validate_map_closed(t_parser *parser)
{
	char	**grid_copy;
	int		start_x;
	int		start_y;
	int		ret;

	grid_copy = copy_grid(&parser->map);
	if (!grid_copy)
	{
		return (print_error("Malloc failed"));
	}
	start_x = (int)parser->map.player.x;
	start_y = (int)parser->map.player.y;
	grid_copy[start_y][start_x] = '0';
	ret = flood_fill(grid_copy, &parser->map, start_x, start_y);
	free_grid(grid_copy);
	if (ret == EXIT_FAILURE)
	{
		return (print_error("Map is not closed"));
	}
	return (EXIT_SUCCESS);
}
