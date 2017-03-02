
#include "get_next_line.h"
#include <stdio.h>

int		main()
{
	char *str;
	int	 fd;
	int		i;

	fd = open("test.txt", O_RDWR);
	while ((i = get_next_line(fd, &str)) != 0)
		printf("%d :%s\n", i, str);
	printf("%d\n", i);
	return (0);
}