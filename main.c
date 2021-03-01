/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:44:52 by acrucesp          #+#    #+#             */
/*   Updated: 2021/02/28 21:19:22 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				main()
{
	int			fd;
	char		*str;
	int			r;

	fd = open("file.txt", O_RDONLY);
	r = get_next_line(fd, &str);
	printf("\nendout1=>%s<\n\n", str);
	r = get_next_line(fd, &str);
	printf("\nendout2=>%s<\n\n", str);
	r = get_next_line(fd, &str);
	printf("\nvacia endout3=>%s<\n\n", str);
	r = get_next_line(fd, &str);
	printf("\nendout4=>%s<\n\n", str);
	r = get_next_line(fd, &str);
	printf("\nendout5=>%s<\n\n", str);
	r = get_next_line(fd, &str);
	printf("\nendout6=>%s<\n\n", str);
	r = get_next_line(fd, &str);
	printf("\nendout7=>%s<\n\n", str);
	//system("leaks a.out");
	return (0);
}
