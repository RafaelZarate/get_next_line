/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 01:14:57 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/05 09:54:49 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static	char	*c_buff = NULL;
	int				ret;
	char			buff[BUFF_SIZE];
	int				i;

	ret = 0;
	if (fd < 0 || !line)
		return (-1);
	if (c_buff == NULL)
		c_buff = ft_strnew(0);
	if (!ft_strchr(c_buff, '\n'))
	{
		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			c_buff = ft_strjoin(c_buff, buff);
			if (ft_strchr(c_buff, '\n'))
				break ;
		}
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!c_buff[0] || !c_buff))
		return (0);
	else
	{
		i = 0;
		while (c_buff[i] && c_buff[i] != '\n')
			i++;
		if (c_buff[i] == '\n')
		{
			*line = ft_strsub(c_buff, 0, i);
			c_buff = ft_strsub(c_buff, i + 1, ft_strlen(c_buff) - i - 1);
		}
		else if (c_buff[i] == '\0')
		{
			*line = ft_strsub(c_buff, 0, i);
			c_buff = NULL;
		}
		return (1);
	}
}
