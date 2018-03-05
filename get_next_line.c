/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 01:14:57 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/05 10:03:05 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static	char	*c_buff[5000];
	int				ret;
	char			buff[BUFF_SIZE];
	char			*tmp;
	int				i;

	ret = 0;
	if (fd < 0 || !line)
		return (-1);
	if (c_buff[fd] == NULL)
		c_buff[fd] = ft_strnew(0);
	if (!ft_strchr(c_buff[fd], '\n'))
	{
		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			tmp = ft_strjoin(c_buff[fd], buff);
			free(c_buff[fd]);
			c_buff[fd] = tmp;
			if (ft_strchr(c_buff[fd], '\n'))
				break ;
		}
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!c_buff[fd][0] || !c_buff[fd]))
		return (0);
	else
	{
		i = 0;
		while (c_buff[fd][i] && c_buff[fd][i] != '\n')
			i++;
		if (c_buff[fd][i] == '\n')
		{
			*line = ft_strsub(c_buff[fd], 0, i);
			tmp = ft_strsub(c_buff[fd], i + 1, ft_strlen(c_buff[fd]) - i - 1);
			free(c_buff[fd]);
			c_buff[fd] = tmp;
		}
		else if (c_buff[fd][i] == '\0')
		{
			*line = ft_strsub(c_buff[fd], 0, i);
			free(c_buff[fd]);
			c_buff[fd] = NULL;
		}
		return (1);
	}
}
