/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:02:47 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/06 11:33:21 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	validate_indentifier(char *line, int i)
{
	if (ft_strncmp(line + i, "NO", 2))
		return (NO);
	if (ft_strncmp(line + i, "SO", 2))
		return (SO);
	if (ft_strncmp(line + i, "WE", 2))
		return (WE);
	if (ft_strncmp(line + i, "EA", 2))
		return (EA);
	if (ft_strncmp(line + i, "F", 2))
		return (F);
	if (ft_strncmp(line + i, "C", 2))
		return (C);
	else
		return (Unknown);
}

int	is_reached_map(line, i, m_flag)
{
	if (condition)
	{
		/* code */
	}
	;
}
