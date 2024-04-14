/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:34:51 by aboukezi          #+#    #+#             */
/*   Updated: 2024/04/14 17:34:52 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		fd2;
	int		i;

	i = 0;
	fd = open("testfiles/42blockchain.txt", O_RDONLY);
	fd2 = open("testfiles/emptyfile.txt", O_RDONLY);
	while (i < 1000000)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		i++;
	}
	printf("Ce fichier contient %i lignes", i);
	line = get_next_line(fd2);
	printf("\nLe contenu de emptyfile.txt est : %s.", line);
}
