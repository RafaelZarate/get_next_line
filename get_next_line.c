/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 06:18:40 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/04 08:24:20 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_line(char *c_buff, char **line, int ret)
{
	int i;
	char	*tmp;

	i = 0;
	while (c_buff[i] && c_buff[i] != '\n')
		i++;
	if (c_buff[i] == '\n')
	{
		*line = ft_strsub(c_buff, 0, i);
		tmp = ft_strncpy(c_buff, i + 1, ft_strlen(c_buff) - 1 - i);
		c_buff = tmp;
		free(tmp);
	}ret++;
	// else
	// {
	// 	if (ret == 0)
	// 		return (0);
	// 	*line = ft_strsub(c_buff, 0, i);
	// 	ft_memdel((void *)&c_buff);
	// }
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*c_buff = NULL;
	int			ret;
	int			n;
	char		*tmp;
	char		buff[BUFF_SIZE + 1];	

	if (!line || fd < 0)
		return (-1);
	if (c_buff == NULL)
		c_buff = ft_strnew(0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(c_buff, buff);
		c_buff = tmp;
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret > 0)
	{
		n = read_line(c_buff, line, ret);
		return (n);
	}
	else
	{
		*line = c_buff;
		return (0);
	}
}
