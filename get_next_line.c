/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:46:20 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/02 14:46:22 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_short(char *str, int len)
{
		char	*new;
		int		i;

		if ((new = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
			return (new);
		i = 0;
		ft_bzero(new, BUFF_SIZE);
		while (len + i < BUFF_SIZE)
		{
			new[i] = str[len + i];
			i++;
		}
		free(str);
		return (new);
}

int		get_next_line(const int fd, char **line)
{
	static char		*tmp = NULL;

	if (tmp == NULL)
	{
		if ((tmp = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) != NULL)
			ft_bzero(tmp, BUFF_SIZE);
		if (tmp == NULL || (read(fd, tmp, BUFF_SIZE) == -1) || line == NULL)
		{
			tmp = NULL;
			return (-1);
		}
	}
	*line = ft_strdup("");
	if (ft_strlen(tmp) == 0 && read(fd, tmp, BUFF_SIZE) == 0)
	{
		tmp = NULL;
		return (0);
	}
	while (ft_line(tmp) == (int)ft_strlen(tmp) && ft_strlen(tmp) != 0)
	{
		*line = ft_strjoin_free(*line, tmp, 1);
		ft_bzero(tmp, BUFF_SIZE);
		read(fd, tmp, BUFF_SIZE);
	}
	if (ft_strlen(tmp) != 0)
	{
		*line = ft_strnjoin(*line, tmp, ft_line(tmp));
		tmp = ft_short(tmp, ft_line(tmp) + 1);
	}
	return (1);
}
