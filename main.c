/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:05:27 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/05 05:23:58 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char *s;
	int n;
	int fd;

	fd = open("test.txt", O_RDONLY);
	while ((n = get_next_line(fd, &s)) > 0)
		ft_putstr(s);
	ft_putstr(s);
	close(fd);
	return (1);
}