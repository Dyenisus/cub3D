/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:06:07 by yesoytur          #+#    #+#             */
/*   Updated: 2026/04/05 15:56:55 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "include.h"

int		print_error(char *message);
int		is_invalid_input(int ac, char *path);
t_map	*parse(char *path);
void	init_parser(t_parser *parser, char *path);
int		read_and_store(t_parser *parser);


#endif
