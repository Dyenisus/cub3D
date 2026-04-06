/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 22:27:58 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/06 20:10:46 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	update_map_size(t_parser *parser, char *line)
{
	int	len;

	len = ft_strlen(line);
	parser->map.height++;
	if (len > parser->map.width)
	{
		parser->map.width = len;
	}
}

static int	line_has_only_chars(char *line, char *allowed)
{
	int	i;

	if (!line)
	{
		return (0);
	}
	i = 0;
	while (line[i])
	{
		if (!ft_strchr(allowed, line[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_empty_line(char *line)
{
	return (line_has_only_chars(line, " \t"));
}

int	is_map_line(char *line)
{
	if (!line || !line[0])
	{
		return (0);
	}
	return (line_has_only_chars(line, "01NSEW "));
}

int	has_only_digits(char *line)
{
	return (line_has_only_chars(line, "0123456789"));
}
