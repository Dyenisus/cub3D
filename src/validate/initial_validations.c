/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_validations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:00:53 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/03 13:08:02 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	is_file_readable(const char *map_str);

void	initial_validations(int	ac, char **av)
{
	size_t	len;
	char 	*map_str;
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
	ssize_t	ret;
	int		fd;
	char	buf;

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

// Validate ac count, is av exist, is av extension correct, is av a secret file, is av opanable file and is av a directory.