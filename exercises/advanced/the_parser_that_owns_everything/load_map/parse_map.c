
#include <stdlib.h>
#include "fdf.h"
#include "load_map.h"
#include "load_map_internal.h"

void	parse_map(char *filepath, t_model *model, t_app *app)
{
	int		fd;
	char	*line;

	fd = try_open(filepath, app);
	//line = try_get_next_line(fd, app);
	//set_model_xyz(fd, line, model, app);
}
