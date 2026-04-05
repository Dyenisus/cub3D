/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 21:36:14 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/05 16:10:35 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_color(t_color *color)
{
	color->red = -1;
	color->green = -1;
	color->blue = -1;
	color->value = -1;
}

static void	init_player(t_player *player)
{
	player->x = -1;
	player->y = -1;
	player->dir = '\0';
}

static void	init_map(t_map *map, char *path)
{
	map->file_path = path;
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->north.path = NULL;
	map->south.path = NULL;
	map->west.path = NULL;
	map->east.path = NULL;
	init_color(&map->floor_color);
	init_color(&map->ceiling_color);
	init_player(&map->player);
}

void	init_parser(t_parser *parser, char *path)
{
	init_map(&parser->map, path);
	parser->lines = NULL;
	parser->line_count = 0;
	parser->capacity = 0;
	parser->has_north_texture = 0;
	parser->has_south_texture = 0;
	parser->has_west_texture = 0;
	parser->has_east_texture = 0;
	parser->has_floor_color = 0;
	parser->has_ceiling_color = 0;
	parser->player_count = 0;
}
