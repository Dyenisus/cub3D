/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:17:51 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/09 21:30:06 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (is_invalid_input(ac, av[1]))
	{
		return (EXIT_FAILURE);
	}
	map = parse(av[1]);
	if (!map)
	{
		return (EXIT_FAILURE);
	}
	if (start_game(map) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}