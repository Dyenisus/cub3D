/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:31:26 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/04 17:34:19 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	validate_parse_flag(int *flag)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (flag[i] != 1)
			return (1);
		i++;
	}
	return (0);
}
