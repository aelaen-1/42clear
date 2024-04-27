/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:27:42 by aboukezi          #+#    #+#             */
/*   Updated: 2024/04/27 19:27:43 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_file(int fd, char *filetoread)
{
	char	*buffer;
	int		read_bytes;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
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
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!filetoread)
			filetoread = ft_calloc(1, 1);
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

ssize_t	go_to_nl(char *save)
{
	ssize_t		i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (-1);
	}
	return (i);
}

char	*ft_next(char *save)
{
	ssize_t		i;
	ssize_t		j;
	char		*next;

	i = go_to_nl(save);
	if (i == -1)
		return (NULL);
	next = malloc((ft_strlen(save) - i) * sizeof(char));
	if (!next)
		return (NULL);
	j = 0;
	while (save[++i])
		next[j++] = save[i];
	next[j] = '\0';
	j = 0;
	while (next[j])
	{
		save[j] = next[j];
		j++;
	}
	save[j] = '\0';
	free(next);
	return (save);
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
	if (line == NULL || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	save = ft_next(save);
	if (save != NULL && ft_strlen(save) == 0)
	{
		free(save);
		save = NULL;
	}
	return (line);
}
