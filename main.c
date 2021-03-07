/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:44:52 by acrucesp          #+#    #+#             */
/*   Updated: 2021/03/07 18:10:02 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				main()
{
	int			fd;
	char		*str;
	int			r;
	int			i;

	i = 0;
	fd = open("lotr.txt", O_RDONLY);
/* 	get_next_line(fd, &str);
	printf("%s", str); */
	while ((r = get_next_line(fd, &str)))
	{
		printf("line %i=>%s<\n", i + 1, str);
		free(str);
		i++;
	}
	printf("%s", str);
	free(str);
	//system("leaks a.out");
	return (0);
}
