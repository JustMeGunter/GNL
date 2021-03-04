/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:43:12 by acrucesp          #+#    #+#             */
/*   Updated: 2021/03/04 21:49:03 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			sv_stcmem(char *buff, char **stc_mem, int p_end)
{
	char		*aux_mem;
	char		*aux_buff;
	int			i;

	i = 0;
	if (stc_mem)
	{
		aux_mem = ft_strdup(*stc_mem);
		free(*stc_mem);
		*stc_mem = 0;
		aux_buff = ft_substr(buff, p_end, ft_strlen(buff));
		*stc_mem = ft_strjoin(aux_mem, aux_buff);
		free(aux_mem);
		aux_mem = 0;
		free(aux_buff);
		aux_buff = 0;
	}
	else
		*stc_mem = ft_strdup(buff);		
}

int				h_end(char *buff, char **line, char **stc_mem)
{
	char		*the_end;
	int			p_end;

	p_end = 0;
	the_end = ft_strrchr(buff, 10);
	if (the_end)
	{
		if (ft_strlen(the_end) < ft_strlen(buff))
			p_end = ft_strlen(buff) - ft_strlen(the_end) - 1;
		else
			p_end = 0;
		if (*stc_mem)
		{
			*line = ft_strjoin(*stc_mem, ft_substr(buff, 0, p_end));
			if (p_end)
				*stc_mem = ft_strdup(the_end);
			return (1);
		}
		else
		{
			*line = ft_substr(buff, 0, p_end);
			if (p_end)
				*stc_mem = ft_strdup(the_end);
			return (1);
		}
	}
	else
		sv_stcmem(buff, stc_mem, p_end);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*stc_mem;
	char		*buff;

	if (line == NULL || fd == -1 || BUFFER_SIZE < 1)
		return (-1);
	if (!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	buff[BUFFER_SIZE] = '\0';
	while (read(fd, buff, BUFFER_SIZE))
	{
		if (h_end(buff, line, &stc_mem))
		{
			free(buff);
			buff = 0;
			return (1);
		}
	}
	return (0);
}
