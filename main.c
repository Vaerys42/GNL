/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:57:22 by kboucaud          #+#    #+#             */
/*   Updated: 2017/04/25 14:57:23 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	char	*str;
	int		ret;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &str)) > 0)
		printf("%d :%s\n", ret, str);
	printf("%d :%s\n", ret, str);
}
