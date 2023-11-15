/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:37:13 by rgiraud           #+#    #+#             */
/*   Updated: 2023/11/15 17:22:02 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *find_newline(const char *s)
{
	if (!s)
		return (NULL);
    while (s && *s)
    {
        if (*s == '\n')
            return (char *)s;
        s++;
    }
    return (NULL);
}


size_t	ft_strlen(char *result)
{
	size_t	size;

	size = 0;
	while (result[size])
	{
		size++;
	}
	return (size);
}

char	*ft_strdup(char *s, char *new_part)
{
	char	*result;
	size_t	len;

	if (new_part)
		len = (size_t)new_part - (size_t)s + 1;
	else
		len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s, len + 1);
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (src[i] && i < (n - 1))
		{
			dst[i] = src[i];
			i++;
		}
		if (n != 0)
			dst[i] = '\0';
	}
	return (ft_strlen((char *)src));
}

char	*ft_strjoin(char *s1, char const *s2, size_t bytes_read)
{
	size_t	len_s1;
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	result = (char *)malloc((len_s1 + bytes_read + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < len_s1)
		result[i] = s1[i];
	free(s1);
	s1 = NULL;
	while (++j < bytes_read)
		result[i + j] = s2[j];
	result[i + j] = '\0';
	return (result);
}
