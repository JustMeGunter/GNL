/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:44:03 by acrucesp          #+#    #+#             */
/*   Updated: 2021/03/09 16:36:11 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t			ft_strlen(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strdup(char *s)
{
	char		*aux;
	int			i;

	i = 0;
	if (!s)
		return (0);
	if (!(aux = malloc(ft_strlen(s) * sizeof(char) + 1)))
		return (0);
	while (s[i])
	{
		aux[i] = s[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

char			*ft_strjoin(char *str1, char *str2)
{
	int			i;
	int			j;
	size_t		len;
	char		*nw_str;

	if (!str1)
		return (0);
	i = 0;
	j = 0;
	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	if (!(nw_str = malloc(sizeof(char) * len)))
		return (0);
	while (len-- && str1[j])
		nw_str[i++] = str1[j++];
	j = 0;
	while (len-- && str2[j])
		nw_str[i++] = str2[j++];
	nw_str[i] = '\0';
	return (nw_str);
}

char			*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s++ == c)
			return ((char *)s);
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char			*ft_substr(char *s, unsigned int start, size_t len)
{
	int			i;
	char		*aux;
	char		*cpstr;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		if (!(cpstr = malloc(sizeof(char) * 1)))
			return (0);
		*cpstr = '\0';
		return (cpstr);
	}
	aux = (char *)s;
	if (!(cpstr = malloc(sizeof(char) * len + 1)))
		return (0);
	while (s[start] && len--)
		cpstr[i++] = aux[start++];
	cpstr[i] = '\0';
	return (cpstr);
}
