/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrive_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:20:04 by yesoytur          #+#    #+#             */
/*   Updated: 2026/01/03 12:59:16 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static char	**append_line(char **arr, char *line, int count);
static char	**read_gnl(int fd);

char	**retrive_lines(char *map_path)
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

