/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:06:15 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/03 14:03:21 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	free_2d(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_tex(t_tex *tex)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tex->tex[i])
			free(tex->tex[i]);
		i++;
	}
}

void	free_tmp(t_tmp *tmp)
{
	free_tex(&(tmp->tex));
	if (tmp->f_str)
	{
		free(tmp->f_str);
		tmp->f_str = NULL;
	}
	if (tmp->c_str)
	{
		free(tmp->c_str);
		tmp->c_str = NULL;
	}
	free_2d(tmp->map);
}

void	free_tmp_allocs(t_tmp *tmp)
{
	if (tmp->f_str)
	{
		free(tmp->f_str);
		tmp->f_str = NULL;
	}
	if (tmp->c_str)
	{
		free(tmp->c_str);
		tmp->c_str = NULL;
	}
}
