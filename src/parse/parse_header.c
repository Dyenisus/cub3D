/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:34:39 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/06 11:30:03 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	parse_header(char **lines, int *i, t_tmp *tmp)
{
	int		*h_flag;
	char	*line;
	int		m_flag;

	h_flag = ft_calloc(6, sizeof(int));
	if (!h_flag)
		return (1);
	m_flag = 0;
	while (lines[*i])
	{
		line = lines[*i];
		if (extract_path(line, tmp, h_flag, &m_flag))
			return (1);
		if (m_flag == 1)
			break ;
		(*i)++;
	}
	return (0);
}

int	extract_path(char *line, t_tmp *tmp, int *h_flag, int *m_flag)
{
	int	i;
	int	h;

	i = 0;
	ft_skipspace(line, &i);
	if (line[i] == '\n')
		return (0);
	h = validate_indentifier(line, i);
	if (h == -1)
		return (is_reached_map(line, i, m_flag));
}
