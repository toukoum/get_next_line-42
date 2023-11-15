/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:37:20 by rgiraud           #+#    #+#             */
/*   Updated: 2023/11/15 18:46:51 by rgiraud          ###   ########.fr       */
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

char	*ft_strdup(char *s, char *new_part, int size);
size_t	ft_strlen(char *result);
char	*find_newline(const char *s);
char	*ft_strjoin(char *s1, char const *s2, size_t bytes_read);
int		read_from_fd(int fd, char *buffer, char **stash);
int		ft_realloc(char **stash, int fd, char *new_part);
char	*get_next_line(int fd);
char	*construct_line(char *buffer, int fd, char **stash, int bytes_read);

#endif