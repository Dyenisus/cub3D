/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 23:13:27 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/06 20:34:30 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	parse_component(char *raw, int *dst)
{
	int		value;
	char	*trimmed;

	trimmed = ft_strtrim(raw, " \t");
	if (!trimmed)
		return (print_error("Malloc failed"));
	if (!*trimmed)
	{
		free(trimmed);
		return (print_error("Missing RGB value"));
	}
	if (!has_only_digits(trimmed))
	{
		free(trimmed);
		return (print_error("Invalid RGB value"));
	}
	value = ft_atoi(trimmed);
	free(trimmed);
	if (value < 0 || value > 255)
		return (print_error("RGB value out of range"));
	*dst = value;
	return (EXIT_SUCCESS);
}

static int	parse_rgb(char **parts, t_color *color)
{
	if (parse_component(parts[0], &color->red) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	if (parse_component(parts[1], &color->green) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	if (parse_component(parts[2], &color->blue) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	count_parts(char **parts)
{
	int	i;

	i = 0;
	while (parts[i])
	{
		i++;
	}
	return (i);
}

int	parse_color_value(char *value, t_color *color)
{
	char	**parts;

	parts = ft_split(value, ',');
	if (!parts)
		return (print_error("Malloc failed"));
	if (count_parts(parts) != 3)
	{
		free_2d_array(parts);
		return (print_error("Invalid color format"));
	}
	if (parse_rgb(parts, color) == EXIT_FAILURE)
	{
		free_2d_array(parts);
		return (EXIT_FAILURE);
	}
	free_2d_array(parts);
	color->value = (color->red << 16) | (color->green << 8) | color->blue;
	return (EXIT_SUCCESS);
}
