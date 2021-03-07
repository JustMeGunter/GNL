/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:43:12 by acrucesp          #+#    #+#             */
/*   Updated: 2021/03/07 16:57:32 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				return_end(char *buff, char **line, char **stc_mem)
{
	int			p_end;
	char		*remaind;
	char		*aux_buff;
	p_end = 0;
	remaind = ft_strchr(buff, '\n');
	if (remaind)
		p_end = ft_strlen(buff) - ft_strlen(remaind);
	aux_buff = ft_substr(buff, 0, p_end - 1);
	free(buff);
	buff = aux_buff;
	if (*stc_mem)
	{
		*line = ft_strjoin(*stc_mem, buff);
		free(*stc_mem);
		*stc_mem = 0;
	}
	else
		*line = ft_strdup(buff);
	if (remaind)
		*stc_mem = ft_strdup(remaind);
	free(buff);
	buff = 0;
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*stc_mem = 0;
	char		*buff;
	char		*aux_buff;
	ssize_t		sz_read;

	if (line == NULL || fd == -1 || BUFFER_SIZE < 1)
		return (-1);
	if (stc_mem && ft_strchr(stc_mem, '\n'))
	{
		buff = ft_strdup(stc_mem);
		free (stc_mem);
		stc_mem = 0;
		return (return_end(buff, line, &stc_mem));
	}
	if (!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	sz_read = read(fd, buff, BUFFER_SIZE);
	buff[sz_read] = '\0';
	while (sz_read && !ft_strchr(buff, '\n'))
	{
		if (stc_mem)
		{
			aux_buff = ft_strjoin(stc_mem, buff);
			free(stc_mem);
			stc_mem = aux_buff;
		}
		else
			stc_mem = ft_strdup(buff);	
		sz_read = read(fd, buff, BUFFER_SIZE);
		buff[sz_read] = '\0';
	}
	return (return_end(buff, line, &stc_mem) && sz_read > 0);
}
