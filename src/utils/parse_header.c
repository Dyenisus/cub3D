/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:12:31 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/06 10:08:31 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	is_skipspace(char *line, int *index)
{
	int		skipped;
	char	c;

	skipped = 0;
	while (line[*index])
	{
		c = line[*index];
		if (c == ' ' || (c >= '\t' && c <= '\r'))
		{
			(*index)++;
			skipped++;
		}
		else
		{
			break ;
		}
	}
	return (skipped);
}
