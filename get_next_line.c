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
	if (ft_strlen(tmp) == 0 && read(fd, tmp, BUFF_SIZE) == 0)
	{
		tmp = NULL;
		return (0);
	}
	next(line, &tmp, fd);
	if (ft_strlen(tmp) != 0)
	{
		*line = ft_strnjoin(*line, tmp, ft_line(tmp));
		tmp = ft_short(tmp, ft_line(tmp));
	}
	return (tmp == NULL) ? -1 : 1;
}

int		next(char **line, char **tmp, int fd)
{
	*line = ft_strdup("");
	while (tmp[0][ft_line(tmp[0])] == 0 && ft_strlen(tmp[0]) != 0)
	{
		if (*line == NULL)
			return (-1);
		*line = ft_strjoin(*line, tmp[0]);
		if ((tmp[0] = read_line(fd)) == NULL)
			return (-1);
	}
	return (0);
}

char	*read_line(int fd)
{
	char	*new;

	if ((new = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (new);
	ft_bzero(new, BUFF_SIZE);
	read(fd, new, BUFF_SIZE);
	return (new);
}

int		ft_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_short(char *str, int size)
{
	char	*new;
	int		i;
	int		len;

	size++;
	len = ft_strlen(str) - size + 1;
	if ((new = (char*)malloc(sizeof(char) * len)) == NULL)
		return (new);
	i = 0;
	while (str[size + i] != 0)
	{
		new[i] = str[size + i];
		i++;
	}
	new[i] = 0;
	return (new);
}
