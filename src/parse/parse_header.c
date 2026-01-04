/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:34:39 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/04 18:17:48 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	parse_header_loop(char *line, t_tmp *tmp, int *flag);

int	parse_header(char **lines, t_tmp *tmp)
{
	int	*flag;
	int	i;

	flag = ft_calloc(6, sizeof(int));
	if (!flag)
		return (1);
	i = 0;
	while (lines[i])
	{
		if (parse_header_loop(lines[i], tmp, flag))
		{
			free(flag);
			return (1);
		}
		i++;
	}
	return (0);
}

int	parse_header_loop(char *line, t_tmp *tmp, int *flag)
{
	int	j;

	j = 0;
	while (line[j])
	{
		ft_skipspace(line, &j);
		if (line_to_tmp(line, j, flag, tmp))
			break ;
		j++;
	}
	if (validate_parse_flag(flag))
		return (1);
	return (0);
}

int	line_to_tmp(char *line, int index, int *flag, t_tmp *tmp)
{
}
