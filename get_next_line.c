/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 06:18:40 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/02 20:30:07 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_line(const int fd)
{
	int i;
	static char *c_buff;
	int ret;

	i = -1;
	if (c_buff == NULL)
	{
		read_buff(fd);
	}
	c_buff = ft_strnew(BUFF_SIZE);
	
}

int		get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int c;
	int i;
	
	c = 0;
	i = -1;
	
	return (1);
}
