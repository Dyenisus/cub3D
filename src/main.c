/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:54:49 by yesoytur          #+#    #+#             */
/*   Updated: 2025/12/09 11:09:05 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int ac, char **av)
{
	t_map	*map;
	// Check ac and av
	// Check av string
	initial_checks(ac, av);
	// Check map file
	map = parse_map_file(av[1]);
	if (!map)
		return (1);
	// Init game loop
	init_asset();
	init_game();
	// Free all and close
	free_all_ext();
}
