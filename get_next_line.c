/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 01:14:57 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/05 05:25:18 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
    static  char    *c_buff = NULL;
    int             ret;
    char            buff[BUFF_SIZE];
    int             i;

    ret = 0;
    if (c_buff == NULL)
            c_buff = ft_strnew(0);
    if (!ft_strchr(c_buff, '\n'))
    {
        while ((ret = read(fd, buff, BUFF_SIZE)) && !ft_strchr(c_buff, '\n'))
        {
            buff[ret] = '\0';
            c_buff = ft_strjoin(c_buff, buff);
			if (ft_strchr(c_buff, '\n'))
				break ;
        }
    }
    else if (ft_strchr(c_buff, '\n'))
    {
        i = 0;
        while (c_buff[i] && c_buff[i] != '\n')
            i++;
        *line = ft_strsub(c_buff, 0, i);
		c_buff = ft_strsub(c_buff, i + 1, ft_strlen(c_buff) - i);
        return (1);
    }
    if (ret == -1)
        return (-1);
    else if (ret == 0 && !c_buff[0])
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
			
			return (0);
		}
		return (1);
    }
}