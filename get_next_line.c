/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:43:12 by acrucesp          #+#    #+#             */
/*   Updated: 2021/03/06 17:56:55 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				return_end(char *buff, char **line, char **stc_mem)
{
	int			p_end;
	char		*aux;

	p_end = 0;
	aux = ft_strchr(buff, 10);
	if (aux)
		p_end = ft_strlen(buff) - ft_strlen(aux);
	if (*stc_mem)
	{
		buff = ft_substr(buff, 0, p_end);
		*line = ft_strjoin(*stc_mem, buff);
	}
	else
	{
		buff = ft_substr(buff, 0, p_end);
		*line = ft_strdup(buff);
	}
	*stc_mem = ft_strdup(aux);
	free(buff);
	buff = 0;
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*stc_mem;
	char		*buff;
	ssize_t		sz_read;

	if (line == NULL || fd == -1 || BUFFER_SIZE < 1)
		return (-1);
	if (stc_mem && ft_strchr(stc_mem, 10))
	{
		buff = ft_strdup(stc_mem);
		free (stc_mem);
		stc_mem = 0;
		return_end(buff, line, &stc_mem);
		return (1);
	}
	if (!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	sz_read = read(fd, buff, BUFFER_SIZE);
	buff[sz_read] = '\0';
	while (sz_read && !ft_strchr(buff, 10))
	{
		if (stc_mem)
			stc_mem = ft_strjoin(stc_mem, buff);
		else
			stc_mem = ft_strdup(buff);	
		sz_read = read(fd, buff, BUFFER_SIZE);
	}
	if (return_end(buff, line, &stc_mem))
		return (1);
	return (0);
}
