/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 13:04:07 by kboucaud          #+#    #+#             */
/*   Updated: 2017/01/15 13:04:09 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 5

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

int		get_next_line(const int fd, char **line);
char	*ft_short(char *str, int size);
int		ft_line(char *str);
char	*ft_end(int fd);

#endif
