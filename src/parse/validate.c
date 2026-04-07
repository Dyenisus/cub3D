/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:17:59 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/07 22:17:21 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	validate(t_parser *parser)
{
	if (validate_textures(&parser->map) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	if (validate_cells(parser) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	if (validate_map_closed(parser) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
