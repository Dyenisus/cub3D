/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:12:31 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/04 17:32:35 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_skipspace(char *line, int *index)
{
	char	c;

	while (line[*index])
	{
		c = line[*index];
		if (c == ' ' || (c >= '\t' && c <= '\r'))
		{
			(*index)++;
		}
		else
		{
			return ;
		}
	}
}

int	ft_isdirection(char *line, int index, int *flag)
{
	if (ft_strncmp(line + index, "NO", 2))
	{
		flag[NO]++;
		return (NO);
	}
	else if (ft_strncmp(line + index, "SO", 2))
	{
		flag[SO]++;
		return (SO);
	}
	else if (ft_strncmp(line + index, "WE", 2))
	{
		flag[WE]++;
		return (WE);
	}
	else if (ft_strncmp(line + index, "EA", 2))
	{
		flag[EA]++;
		return (EA);
	}
	else
	{
		return (-1);
	}
}

int	ft_is_f_or_c(char *line, int index, int *flag)
{
	if (ft_strncmp(line + index, "F ", 2))
	{
		flag[F]++;
		return (F);
	}
	if (ft_strncmp(line + index, "C ", 2))
	{
		flag[C]++;
		return (C);
	}
	else
	{
		return (-1);
	}
}

