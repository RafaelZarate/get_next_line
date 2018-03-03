/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 06:18:40 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/02 22:30:01 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_line(const int fd, char **line)
{
	int			i;
	int			i2;
	static char	*c_buff = NULL;
	int			ret;

	i = 0;
	i2 = -1;
	if (c_buff == NULL)
	{
		ft_putstr("LOL");
		c_buff = ft_strnew(BUFF_SIZE);
		ret = read(fd, c_buff, BUFF_SIZE);
	}
	while (c_buff[i] != EOF && c_buff[i] != '\n')
		i++;
	if (i > 0)
	{
		ft_strncpy(*line, c_buff, i);
		ft_memmove(c_buff, c_buff + i + 1, ft_strlen(c_buff));
	}
}

int		get_next_line(const int fd, char **line)
{
	// int c;
	// int i;

	// c = 0;
	// i = -1;
	read_line(fd, line);
	return (1);
}
