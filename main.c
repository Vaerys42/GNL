/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:02:26 by kboucaud          #+#    #+#             */
/*   Updated: 2017/03/24 13:02:27 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int		fd;
	int		ret;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &str)) > 0)
		printf("%d :%s\n", ret, str);
	printf("%d :%s\n", ret, str);
}
