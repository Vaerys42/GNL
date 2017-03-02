#include <stdio.h>
#include "get_next_line.h"

int			main()
{
	int fd;
	int	i;
	char *str;

	fd = open("test", O_RDONLY);
	while ((i = get_next_line(fd, &str)) != 0)
		printf("%d :%s\n", i, str);
	return (0);
}