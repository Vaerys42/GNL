/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 13:04:00 by kboucaud          #+#    #+#             */
/*   Updated: 2017/01/15 13:04:01 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char			*file;
	char				*str;

	str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_bzero(str, BUFF_SIZE);
	if (file == NULL)
	{
		file = ft_strdup("");
		if (read(fd, str, BUFF_SIZE) == -1)
			return (-1);
		while (ft_strlen(str) != 0)
		{
			file = ft_strjoin(file, str);
			ft_bzero(str, BUFF_SIZE);
			read(fd, str, BUFF_SIZE);
		}
	}
	if (ft_strlen(file) == 0)
		return (0);
	*line = ft_strndup(file, ft_line(file), 0);
	if (file[ft_line(file)] == '\n')
		file = ft_short(file, ft_line(file));
	else
		file = ft_short(file, ft_line(file) - 1);
	return (1);
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
