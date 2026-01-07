/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:34:39 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/07 10:25:18 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	parse_header(char **lines, int *i, t_tmp *tmp)
{
	int		*h_flag;
	char	*line;

	h_flag = ft_calloc(6, sizeof(int));
	if (!h_flag)
		return (0);
	while (lines[*i])
	{
		line = line[*i];
		if (!write_to_tmp(line, tmp, h_flag))
			break ;
		i++;
	}
	
}

// is_header_done, is_header_duplicated, is_gibberish