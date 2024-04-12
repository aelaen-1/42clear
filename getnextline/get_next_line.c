/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:09:39 by aboukezi          #+#    #+#             */
/*   Updated: 2024/03/27 15:09:40 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *filetoread)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while ((read_bytes > 0) && !(ft_strchr(filetoread, '\n')))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(filetoread);
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		filetoread = ft_strjoin(filetoread, buffer);
	}
	free(buffer);
	return (filetoread);
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
	{
		free(next);
		return (NULL);
	}
	j = 0;
	while (save[++i])
		next[j++] = save[i];
	next[j] = '\0';
	free(save);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_file(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	if (!line || !*line)
	{
		free(line);
		return (NULL);
	}
	save = ft_next(save);
	return (line);
}
