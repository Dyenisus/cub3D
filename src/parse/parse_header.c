/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:34:39 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/03 21:11:24 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_skipspace(char *line, int *index);
int	parse_header_loop(char *line, t_tmp *tmp, int *flag);

int	parse_header(char **lines, t_tmp *tmp)
{
	int		*flag;
	int		i;

	flag = ft_calloc(6, sizeof(int));
	if (!flag)
		// return or exit
	i = 0;
	while (lines[i])
	{
		if (parse_header_loop(lines[i], tmp, flag))
			// break or return (-1)
		i++;
	}
	return (0);
}

int	parse_header_loop(char *line, t_tmp *tmp, int *flag)
{
	int		j;

	j = 0;
	while (line[j])
	{
		ft_skipspace(line, &j);
		if ((ft_isdirection(line, j, flag) == -1) || (ft_is_f_or_c(line, j, flag) == -1))
			// return
	}
}

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
