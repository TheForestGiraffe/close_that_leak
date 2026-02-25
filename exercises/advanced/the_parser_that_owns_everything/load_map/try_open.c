
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "fdf.h"

int	try_open(char *filepath, t_app *app)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		perror("try_open failed.");
		destroy_app(app, EXIT_FAILURE);
	}
	return (fd);
}
