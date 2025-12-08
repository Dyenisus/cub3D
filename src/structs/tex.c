/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:34:40 by yesoytur          #+#    #+#             */
/*   Updated: 2025/12/08 11:39:27 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_texture(t_texture *tex)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tex->tex[i] = NULL;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		tex->f_color[i] = -1;
		tex->c_color[i] = -1;
		i++;
	}
}
