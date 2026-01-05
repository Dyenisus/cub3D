/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:31:26 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/05 14:31:20 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	validate_parse_flag(int *flag)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (flag[i] != 1)
			return (1);
		i++;
	}
	return (0);
}

int	validate_map_header(char *line, int index)
{
	char	*current;

	current = line + index; 
	if (!ft_strncmp(current, "NO", 2))
		return (NO);
	if (!ft_strncmp(current, "SO", 2))
		return (SO);
	if (!ft_strncmp(current, "WE", 2))
		return (WE);
	if (!ft_strncmp(current, "EA", 2))
		return (EA);
	if (!ft_strncmp(current, "F", 1))
		return (F);
	if (!ft_strncmp(current, "C", 1))
		return (C);
	else
		return (Unknown);
}
