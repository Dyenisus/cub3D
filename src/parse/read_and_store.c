/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_store.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 15:55:41 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/05 16:57:35 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	copy_old_pointers(char **new_lines, char **old_lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		new_lines[i] = old_lines[i];
		i++;
	}
}

static int	grow_parser_lines(t_parser *parser)
{
	int		new_capacity;
	char	**new_lines;

	if (parser->capacity == 0)
	{
		new_capacity = 16;
	}
	else
	{
		new_capacity = parser->capacity * 2;
	}
	new_lines = ft_calloc((new_capacity + 1), sizeof(char *));
	if (!new_lines)
	{
		return (print_error("Failed to allocate parser lines"));
	}
	copy_old_pointers(new_lines, parser->lines, parser->line_count);
	free(parser->lines);
	parser->lines = new_lines;
	parser->capacity = new_capacity;
	parser->lines[parser->line_count] = NULL;
	return (EXIT_SUCCESS);
}

static int	has_line_capacity(t_parser *parser)
{
	if (parser->line_count == parser->capacity)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	store_line(t_parser *parser, char *line)
{
	if (has_line_capacity(parser) == EXIT_FAILURE)
	{
		if (grow_parser_lines(parser) == EXIT_FAILURE)
		{
			free(line);
			return (EXIT_FAILURE);
		}
	}
	parser->lines[parser->line_count] = line;
	parser->line_count++;
	parser->lines[parser->line_count] = NULL;
	return (EXIT_SUCCESS);
}

int	read_and_store(t_parser *parser)
{
	int		fd;
	char	*line;

	fd = open(parser->map.file_path, O_RDONLY);
	if (fd < 0)
	{
		return (print_error("Failed to open map file"));
	}
	line = get_next_line(fd);
	while (line)
	{
		if (store_line(parser, line) == EXIT_FAILURE)
		{
			close(fd);
			return (EXIT_FAILURE);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
