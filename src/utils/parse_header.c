/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:12:31 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/05 15:07:07 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_skipspace(char *line, int *index)
{
	int		flag;
	char	c;

	flag = 1;
	while (line[*index])
	{
		c = line[*index];
		if (c == ' ' || (c >= '\t' && c <= '\r'))
		{
			(*index)++;
			flag = 0;
		}
		else
		{
			break ;
		}
	}
	return (flag);
}

void	ft_skiptill_nl_or_space(char *line, int *index)
{
	char	c;

	while (line[*index])
	{
		c = line[*index];
		if (c != '\n' && c != ' ' && (c >= '\r' || c <= '\t'))
		{
			(*index)++;
		}
		else
		{
			return ;
		}
	}
}

