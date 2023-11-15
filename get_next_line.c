/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:37:16 by rgiraud           #+#    #+#             */
/*   Updated: 2023/11/15 18:00:44 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*result;
	size_t			i;
	unsigned char	*temp;

	if (size && count > __SIZE_MAX__ / size)
		return (NULL);
	result = malloc(count * size);
	if (!result)
		return (NULL);
	temp = (unsigned char *)result;
	i = 0;
	while (i++ < count * size)
	{
		*temp = '\0';
		temp++;
	}
	return (result);
}

int	read_from_fd(int fd, char *buffer, char **stash)
{
	size_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		if (stash[fd])
		{
			stash[fd] = ft_strjoin(stash[fd], buffer, bytes_read);
		}
		else
		{
			stash[fd] = ft_strdup(buffer, NULL);
		}
		if (!stash[fd])
			return (-1);
		return (bytes_read);
	}
	if (bytes_read == 0)
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}

int	ft_realloc(char **stash, int fd, char *new_part)
{
	char	*temp;

	if (*(new_part + 1) != '\0')
	{
		temp = ft_strdup(new_part + 1, NULL);
		if (!temp)
			return (0);
	}
	else
		temp = NULL;
	free(stash[fd]);
	stash[fd] = temp;
	return (1);
}

/// printf("ETA de stash:%s, bytes read %d\n", stash[fd], bytes_read);
char	*construct_line(char *buffer, int fd, char **stash, int bytes_read)
{
	char	*new_part;
	char	*result;

	while (bytes_read > 0 || find_newline(stash[fd]))
	{
		new_part = find_newline(stash[fd]);
		if (new_part)
		{
			result = ft_strdup(stash[fd], new_part);
			if (!result || !ft_realloc(stash, fd, new_part))
				return (NULL);
			return (result);
		}
		bytes_read = read_from_fd(fd, buffer, stash);
	}
	if (bytes_read == 0)
	{
		if (!stash[fd])
			return (NULL);
		result = ft_strdup(stash[fd], NULL);
		free(stash[fd]);
		stash[fd] = NULL;
		return (result);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*result;
	static char	*stash[FOPEN_MAX];
	int			bytes_read;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX || read(fd, 0, 0) < 0)
		return (NULL);
	// buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	bytes_read = read_from_fd(fd, buffer, stash);
	result = construct_line(buffer, fd, stash, bytes_read);
	free(buffer);
	return (result);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (2);
// 	}
// 	// while ((line = get_next_line(fd)) != NULL)
// 	// {
// 	// 	printf("GETNEXTLINE:%s\n", line);
// 	// 	free(line);
// 	// }

// 	line = get_next_line(fd);
// 	printf("GETNEXTLINE:%s\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("GETNEXTLINE:%s\n", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("GETNEXTLINE:%s\n", line);
// 	free(line);

// 	if (close(fd) == -1)
// 	{
// 		perror("Error closing file");
// 		return (3);
// 	}
// 	return (0);
// }