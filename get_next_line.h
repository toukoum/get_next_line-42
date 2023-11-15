/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:37:20 by rgiraud           #+#    #+#             */
/*   Updated: 2023/11/15 11:00:08 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*ft_strdup(char *s, char *new_part);
size_t	ft_strlen(char *result);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	*find_newline(const char *s);
char	*ft_strjoin(char *s1, char const *s2, size_t bytes_read);

int		read_from_fd(int fd, char *buffer, char **stash);
int		ft_realloc(char **stash, int fd, char *new_part);
char	*get_next_line(int fd);
char	*construct_line(char *buffer, int fd, char **stash, int bytes_read);

#endif