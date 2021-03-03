/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:43:12 by acrucesp          #+#    #+#             */
/*   Updated: 2021/03/01 21:42:20 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int fd, char **line)
{
	static char *sv_str;
	char		*buff;
	int			p;
	int 		i;

	i = 0;
	if (!(buff = malloc(sizeof(char) * BUFFER_SIZE)))
		return (0);
	if (!sv_str)
	{
		if (!(sv_str = malloc(sizeof(char) * BUFFER_SIZE)))
			return (0);
	}
/* 	printf("\ninit line =>%s\n", *line);
	printf("\ninit sv_str =>%s\n", sv_str); */
	if (sv_str[0] == '\n')
	{
		sv_str++;
		*line[0] = '\0';
		if (buff)
			free(buff);
/* 		printf("\n----------------------------------------------\n\n"); */
		return (1);
	}
	while (read(fd, buff, BUFFER_SIZE))
	{
/* 		printf("\nline start while=>%s\n", *line);
		printf("\nread buff=>%s\n", buff); */
		if (*sv_str != '\0')
		{
			*line = sv_str;
			/* printf("\nbuff sv_str =>%s\n", *line); */
		}
		if ((p = h_end(buff)))
		{
			buff[BUFFER_SIZE] = '\0';
			/* printf("\nhas buff 1 => %s\n", buff); */
			sv_str = ft_substr(buff, p + 1, BUFFER_SIZE - p - 1);
			/* printf("\nresto =>%s\n", sv_str); */
			buff = ft_substr(buff, 0, p);
			/* printf("\nhas buff 2 =>%s\n", buff); */
			*line = ft_strjoin(*line, buff);
			/* printf("\nout =>%s\n", *line); */
			free(buff);
			/* printf("\n----------------------------------------------\n\n"); */
			return (1);
		}
		/* printf("\nline before join=>%s\n", *line);
		printf("buff before join=>%s\n", buff); */
		*line = ft_strjoin(*line, buff);
		/* printf("\n%i line end while=>%s\n", i, *line); */
	}
	free(buff);
	free(sv_str);
	return (0);
}
