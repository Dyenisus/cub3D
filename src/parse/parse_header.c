/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:34:39 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/06 14:12:49 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	line_to_tmp(char *line, int *i, t_tmp *tmp, int h);
static int	extract_path(char *line, t_tmp *tmp, int *h_flag, int *m_flag);


int	parse_header(char **lines, int *i, t_tmp *tmp)
{
	int		*h_flag;
	char	*line;
	int		m_flag;
	int		ret;

	ret = 1;
	h_flag = ft_calloc(6, sizeof(int));
	if (!h_flag)
		return (ret);
	m_flag = 0;
	while (lines[*i])
	{
		line = lines[*i];
		if (extract_path(line, tmp, h_flag, &m_flag))
			return (ret);
		if (m_flag == 1)
			break ;
		(*i)++;
	}
	if (!is_header_done(h_flag))
		ret = 0;
	free(h_flag);
	return (ret);
}

static int	extract_path(char *line, t_tmp *tmp, int *h_flag, int *m_flag)
{
	int	i;
	int	h;

	i = 0;
	ft_skipspace(line, &i);
	if (line[i] == '\n')
		return (0);
	h = validate_indentifier(line, i);
	if (h == -1)
		return (is_reached_map(line, i, h_flag, m_flag));
	line_to_tmp(line, &i, tmp, h);
	h_flag[h]++;
	if (is_header_duplicated(h_flag))
		return (print_err("Duplicated header identifier"));
	return (0);
}

static void	line_to_tmp(char *line, int *i, t_tmp *tmp, int h)
{
	int	start;
	int	end;

	start = *i;
	ft_skiptilleol(line, i);
	end = *i;
	if (h < 4 && !tmp->tex.tex[h])
		tmp->tex.tex[h] = ft_substr(line, start, end - start);
	else if (h == 4 && !tmp->f_str)
		tmp->f_str = ft_substr(line, start, end - start);
	else if (h == 5 && !tmp->c_str)
		tmp->c_str = ft_substr(line, start, end - start);
}
