/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 17:04:19 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/06 19:37:07 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_2d_array(char	**arr)
{
	int	i;

	if (!arr)
	{
		return ;
	}
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_parser(t_parser *parser)
{
	free_2d_array(parser->lines);
	free_2d_array(parser->map.grid);
	free(parser->map.north.path);
	free(parser->map.south.path);
	free(parser->map.west.path);
	free(parser->map.east.path);
}
