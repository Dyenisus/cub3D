/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:02:47 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/07 10:26:03 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	validate_indentifier(char *line, int i)
{
	if (ft_strncmp(line + i, "NO", 2) == 0)
		return (NO);
	if (ft_strncmp(line + i, "SO", 2) == 0)
		return (SO);
	if (ft_strncmp(line + i, "WE", 2) == 0)
		return (WE);
	if (ft_strncmp(line + i, "EA", 2) == 0)
		return (EA);
	if (ft_strncmp(line + i, "F", 2) == 0)
		return (F);
	if (ft_strncmp(line + i, "C", 2) == 0)
		return (C);
	else
		return (Unknown);
}

int	is_header_done(int *h_flag)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (h_flag[i] != 1)
			return (0);
		i++;
	}
	return (1);
}

int	is_header_duplicated(int *h_flag)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (h_flag[i] > 1)
			return (0);
		i++;
	}
	return (1);
}
