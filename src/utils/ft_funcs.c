/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:12:31 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/06 13:13:16 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_isspace(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	return ((uc >= '\t' && uc <= '\r') || uc == ' ');
}

void	ft_skipspace(char *line, int *i)
{
	char	c;

	while (line[*i])
	{
		c = line[*i];
		if (ft_isspace(c))
		{
			(*i)++;
		}
		else
		{
			return ;
		}
	}
}

void	ft_skiptilleol(char *line, int *i)
{
	while (line[*i])
		(*i)++;
}
