/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cells.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:57:03 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/07 22:14:13 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

static void	store_player(t_parser *parser, int x, int y, char dir)
{
	parser->player_count++;
	parser->map.player.x = x + 0.5;
	parser->map.player.y = y + 0.5;
	parser->map.player.dir = dir;
}

static int	check_cell_char(t_parser *parser, int x, int y)
{
	char	cell;

	cell = parser->map.grid[y][x];
	if (is_player_char(cell))
	{
		store_player(parser, x, y ,cell);
	}
	else if (cell != '0' && cell != '1' && cell != ' ')
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	validate_cells(t_parser *parser)
{
	int		x;
	int		y;

	parser->player_count = 0;
	y = 0;
	while (y < parser->map.height)
	{
		x = 0;
		while (x < parser->map.width)
		{
			if (check_cell_char(parser, x, y) == EXIT_FAILURE)
			{
				return (print_error("Invalid map character"));
			}
			x++;
		}
		y++;
	}
	if (parser->player_count != 1)
	{
		return (print_error("Map must contain exactly one player"));
	}
	return (EXIT_SUCCESS);
}
