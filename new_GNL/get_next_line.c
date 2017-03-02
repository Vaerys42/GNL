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
	static char		*tmp;

	if (tmp == NULL)
	{
		tmp = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
		ft_bzero(tmp, BUFF_SIZE);
		if (read(fd, tmp, BUFF_SIZE) == -1)
			return (-1);
	}
	if (ft_strlen(tmp) == 0)
		return (0);
	*line = ft_strdup("");
	while (ft_line(tmp) == (int)ft_strlen(tmp) && ft_strlen(tmp) != 0)
	{
		*line = ft_strjoin(*line, tmp);
		ft_bzero(tmp, BUFF_SIZE);
		read(fd, tmp, BUFF_SIZE);
	}
	*line = ft_strnjoin(*line, tmp, ft_line(tmp));
	tmp = ft_short(tmp, ft_line(tmp));
	if (ft_strlen(tmp) == 0)
		tmp = ft_end(fd);
	return (1);
}

char	*ft_end(int fd)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_bzero(str, BUFF_SIZE);
	read(fd, str, BUFF_SIZE);
	if (ft_strlen(str) == 0)
		return ("");
	return (str);
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

	size++;
	new = (char*)malloc(sizeof(char) * (ft_strlen(str) - size + 1));
	i = 0;
	while (str[size + i] != 0)
	{
		new[i] = str[size + i];
		i++;
	}
	new[i] = 0;
	free(str);
	return (new);
}
