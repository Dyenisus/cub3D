/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:34:39 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/05 15:37:38 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	parse_header_loop(char *line, t_tmp *tmp, int *flag);

int	parse_header(char **lines, t_tmp *tmp)
{
	int	*flag;
	int	i;
	int	ret;

	flag = ft_calloc(6, sizeof(int));
	if (!flag)
		return (1);
	i = 0;
	while (lines[i])
	{
		parse_header_loop(lines[i], tmp, flag);
		i++;
	}
	ret = 0;
	if (validate_parse_flag(flag))
		ret = 1;
	free(flag);
	return (ret);
}

static void	parse_header_loop(char *line, t_tmp *tmp, int *flag)
{
	int	j;

	j = 0;
	while (line[j])
	{
		ft_skipspace(line, &j);
		if (line_to_tmp(line, &j, flag, tmp))
			break ;
		j++;
	}
	return ;
}

int	line_to_tmp(char *line, int *index, int *flag, t_tmp *tmp)
{
	int	h;
	int	start;
	int	end;

	if (line[*index] == '\n')
		return (0);
	h = validate_map_header(line, *index);
	if (h == Unknown)
		return (1);
	if (ft_skipspace(line, index))
		return (1);
	start = (*index);
	ft_skiptill_nl_or_space(line, index);
	end = (*index) - 1;
	if (h < F)
		tmp->tex.tex[h] = ft_substr(line, start, end - start);
	else if (h == F)
		tmp->f_str = ft_substr(line, start, end - start);
	else if (h == C)
		tmp->c_str = ft_substr(line, start, end - start);
	flag[h]++;
	return (0);
}
