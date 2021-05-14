/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:43:12 by acrucesp          #+#    #+#             */
/*   Updated: 2021/05/13 20:03:21 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	return_end(char *buff, char **line, char **stc_mem, int fd)
{
	int			p_end;
	char		*reminder;
	char		*aux_buff;

	p_end = 1;
	reminder = ft_strdup(ft_strchr(buff, '\n'));
	if (reminder)
		p_end = ft_strlen(buff) - ft_strlen(reminder);
	aux_buff = ft_substr(buff, 0, p_end - 1);
	free(buff);
	buff = aux_buff;
	if (stc_mem[fd])
	{
		*line = ft_strjoin(stc_mem[fd], buff);
		free(stc_mem[fd]);
		stc_mem[fd] = 0;
	}
	else
		*line = ft_strdup(buff);
	if (reminder)
		stc_mem[fd] = ft_strdup(reminder);
	free(buff);
	free(reminder);
	buff = 0;
	return (1);
}

void	u_spin_me(char **stc_mem, char *buff, int fd, ssize_t *sz_read)
{
	char		*aux_buff;

	if (stc_mem[fd])
	{
		aux_buff = ft_strjoin(stc_mem[fd], buff);
		free(stc_mem[fd]);
		stc_mem[fd] = aux_buff;
	}
	else
		stc_mem[fd] = ft_strdup(buff);
	*sz_read = read(fd, buff, BUFFER_SIZE);
	buff[*sz_read] = '\0';
}

int	save_free(char **buff, char **stcm, int fd)
{
	*buff = ft_strdup(stcm[fd]);
	free(stcm[fd]);
	stcm[fd] = 0;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*stcm[4096];
	char		*buff;
	ssize_t		sz_read;

	if (line == NULL || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (stcm[fd] && ft_strchr(stcm[fd], '\n')
		&& save_free(&buff, stcm, fd))
		return (return_end(buff, line, stcm, fd));
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	sz_read = read(fd, buff, BUFFER_SIZE);
	if (sz_read < 0)
	{
		free(buff);
		if (stcm[fd])
			free(stcm[fd]);
		return (-1);
	}
	buff[sz_read] = '\0';
	while (sz_read && !ft_strchr(buff, '\n'))
		u_spin_me(stcm, buff, fd, &sz_read);
	return (return_end(buff, line, stcm, fd) && sz_read > 0);
}
