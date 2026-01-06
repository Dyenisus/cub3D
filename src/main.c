/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:54:49 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/06 10:14:06 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int ac, char **av)
{
	t_map	*map;
	// validate args
	initial_validations(ac, av);
	// parse map file
	map = parse_map_file(av[1]);
	if (!map)
		return (1);
	// init game loop
	init_asset();
	init_game();
	// free all and close
	free_all_ext();
}
