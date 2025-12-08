/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:53:19 by yesoytur          #+#    #+#             */
/*   Updated: 2025/12/08 12:46:01 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static char	**retrive_lines(char *map_path);

t_map	*parse_map(char *map_path)
{
	t_tmp		tmp;
	t_map		*map;
	char		**lines; /* [[NO][SO][WE][EA][F][C]] */

	init_tmp(&tmp);
	lines = retrive_lines(map_path);
	if (!lines || !*lines)
	{
		print_err("Invalid Map");
		free_2d(lines);
		return (NULL);
	}
}

static char	**append_line(char **arr, char *line, int count)
{
	char	**new_arr;
	int		i;

	new_arr = malloc(sizeof(char *) * (count + 2));
	if (!new_arr)
	{
		free_2d(arr);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[count] = line;
	new_arr[count + 1] = NULL;
	free(arr);
	return (new_arr);
}

static char	**read_gnl(int fd)
{
	int		count;
	char	*line;
	char	**ret;

	ret = NULL;
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (ret);
		ret = append_line(ret, line, count);
		if (!ret)
		{
			free(line);
			return (NULL);
		}
		count++;
	}
}

static char	**retrive_lines(char *map_path)
{
	int		fd;
	char	**lines;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = read_gnl(fd);
	close(fd);
	return (lines);
}
