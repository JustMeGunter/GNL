/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:43:12 by acrucesp          #+#    #+#             */
/*   Updated: 2021/03/01 17:14:15 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int fd, char **line)
{
	static char *sv_str;
	char		*buff;
	int			p;

	if (!(buff = malloc(sizeof(char) * BUFFER_SIZE)))
		return (0);
	if (!sv_str)
		if (!(sv_str = malloc(sizeof(char) * BUFFER_SIZE)))
			return (0);
	printf("init =>%s\n", *line);
	printf("init =>%s\n", sv_str);
	if (sv_str[0] == '\n')
	{
		sv_str++;
		*line[0] = '\0';
		return (1);
	}
	while (read(fd, buff, BUFFER_SIZE))
	{
		buff[BUFFER_SIZE] = '\0';
		printf("read => %s\n", buff);
		if (sv_str)
		{
			*line = sv_str;
			printf("buff sv_str =>%s\n", *line);
		}
		if ((p = h_end(buff)))
		{
			printf("has buff 1 => %s\n", buff);
			sv_str = ft_substr(buff, p + 1, BUFFER_SIZE);
			printf("resto =>%s\n", sv_str);
			buff = ft_substr(buff, 0, p);
			printf("has buff 2 => %s\n", buff);
			*line = ft_strjoin(*line, buff);
			printf("out =>%s\n", *line);
			free(buff);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
		printf("=>%s\n", *line);
	}
	free(buff);
	free(sv_str);
	return (0);
}
