/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:10:32 by aboukezi          #+#    #+#             */
/*   Updated: 2024/03/27 15:10:35 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	size_t	i;

	if (!s)
		return (NULL);
	if (c == '\0')
		return (s + ft_strlen(s));
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *saved, char *buffer)
{
	size_t	buffer_len;
	size_t	content_len;
	char	*result;
	char	*result_ptr;
	char	*src;

	buffer_len = 0;
	if (!saved && !buffer)
		return (NULL);
	if (saved)
		buffer_len = ft_strlen(saved);
	content_len = ft_strlen(buffer);
	result = (char *)malloc(sizeof(char) * (buffer_len + content_len + 1));
	if (!result)
		return (NULL);
	result_ptr = result;
	src = saved;
	while (src && *src)
		*result_ptr++ = *src++;
	src = (char *)buffer;
	while (src && *src)
		*result_ptr++ = *src++;
	*result_ptr = '\0';
	free(saved);
	return (result);
}

char	*ft_get_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] != '\0' && save[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_next(char *save)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	next = (char *)malloc((ft_strlen(save) - i + 1) * sizeof(char));
	if (!next)
		return (NULL);
	j = 0;
	while (save[++i])
		next[j++] = save[i];
	next[j] = '\0';
	free(save);
	return (next);
}
