/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:43:12 by acrucesp          #+#    #+#             */
/*   Updated: 2021/03/04 17:51:38 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				return_line(char **line, char **stc_str, int fd)
{
	int			i;
	char		*aux_stc;

	i = 0;
	while (stc_str[fd][i])
	{
		if (stc_str[fd][i] == '\n')
		{
			*line = ft_substr(stc_str[fd], 0, i);
			aux_stc = ft_substr(stc_str[fd], i + 1, ft_strlen(stc_str[fd]) - i);
			free(stc_str[fd]);
			stc_str[fd] = NULL;
			stc_str[fd] = aux_stc;
			return (1);
		}
		i++;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*stc_str[4096];
	char		buff[BUFFER_SIZE + 1];
	char		*aux_stc;
	ssize_t		r_read;

	if (line == NULL || fd == -1 || BUFFER_SIZE < 1)
		return (-1);
	while ((r_read = read(fd, buff, BUFFER_SIZE)))
	{
		if (r_read == -1)
			return (-1);
		buff[r_read] = '\0';
		if (stc_str[fd])
		{
			aux_stc = ft_strjoin(stc_str[fd], buff);
			free(stc_str[fd]);
			stc_str[fd] = NULL;
			stc_str[fd] = aux_stc;
			if(return_line(line, stc_str, fd))
				return (1);
		}
		else
		{
			stc_str[fd] = ft_substr(buff, 0, r_read);
			if (return_line(line, stc_str, fd))
				return (1);
		}
	}
	return (0);
}
