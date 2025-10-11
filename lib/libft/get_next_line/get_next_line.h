/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:28:37 by yesoytur          #+#    #+#             */
/*   Updated: 2025/10/10 18:54:10 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

size_t	gnl_len(const char *s);
char	*gnl_chr(const char *s, int c);
void	*gnl_memmove(void *dest, const void *src, size_t n);
int		gnl_append_mem(char **s1, char *s2, size_t size2);
int		gnl_append_str(char **s1, char *s2);
char	*get_next_line(int fd);

#endif