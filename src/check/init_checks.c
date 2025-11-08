/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:00:53 by yesoytur          #+#    #+#             */
/*   Updated: 2025/10/31 21:19:37 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	is_file_readable(const char *map_str);

void	init_checks(int	ac, char **av)
{
	char 	*map_str;
	size_t	len;
	char	*exten;

	map_str = av[1];
	if (ac != 2 || !*map_str)
		print_err_ext("Invalid arguments");
	len = ft_strlen(map_str);
	if (len <= 4)
		print_use_ext("Invalid file extension");
	exten = map_str + (len - 4);
	if (ft_strncmp(exten, ".cub", 4))
		print_use_ext("Invalid file extension");
	if (!ft_strncmp(exten - 1, "/.cub", 5))
		print_use_ext("Invalid secret file");
	is_file_readable(map_str);
}

static void	is_file_readable(const char *map_str)
{
	int		fd;
	char	buf;
	ssize_t	ret;

	fd = open(map_str, O_RDONLY);
	if (fd < 0)
		print_use_ext("File cannot be opened");
	ret = read(fd, &buf, 1);
	close(fd);
	if (ret < 0)
	{
		if (errno == EISDIR)
			print_use_ext("Path is a directory");
		print_err_ext("Read error");
	}
	if (!ret)
		print_err_ext("Empty map");
}

static void	asset_checks()
{
	;
}
