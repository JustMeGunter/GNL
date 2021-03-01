/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:50:28 by acrucesp          #+#    #+#             */
/*   Updated: 2021/03/01 17:10:01 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# define BUFFER_SIZE 32

int			get_next_line(int fd, char **line);
size_t      ft_strlen(char *str);
char		*ft_strjoin(char *str1, char *str2);
int			h_end(char *str);
void		ft_bzero(char *s, size_t n);
char        *ft_substr(char *s, unsigned int start, size_t len);

#endif
