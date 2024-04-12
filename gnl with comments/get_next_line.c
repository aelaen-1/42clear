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

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

/*lis le fichier associe au fd et check s'il trouve une nouvelle ligne ou si le fichier est fini,
il ajoute ce qu'il a lu dans la variable buffer. Ce buffer sera ensuite utilise pour recuperer la 
premiere ligne lors de l'appel de la fonction get next line*/
char	*ft_read_file(int fd, char *filetoread)
{
	char	*buffer;
	int	read_bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 10;
	/* while no error or eof &&  no newline found */
	while (read_bytes > 0 && !(ft_strchr(buffer, '\n')))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		/* end of line or file */
		buffer[read_bytes] = '\0';
		/*concatene les caracteres lus aux precedents, en ajoutant de la memoire*/
		filetoread = ft_strjoin(filetoread, buffer);
	}
	free(buffer);
	return (filetoread);
}

char	*ft_get_line(char *save)
{
	char	*line;
	int		i;

	while (save[i] && save[i] != '\n')
		i++;
	/*malloc line + \n et \0 */
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
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
	/*len of first line */
	while (save[i] && save[i] != '\n')
		i++;
	/*len of file - len of firstline + \0 */
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
	free(save); /*on frit l'ensien buffer*/
	return (next); /*next buffer*/
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
	/* pour le prochain appel, on modifie la valeur de
	buffer (qui sera conservee)*/
	save = ft_next(save);
	return (line);
}
