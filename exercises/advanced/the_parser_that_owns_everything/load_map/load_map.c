
//#include "fdf.h"
//#include "load_map.h"
#include "load_map_internal.h"

t_model	*load_map(char *filepath, t_app *app)
{
	t_model	*model;

	//model = create_model(app);
	//parse_map_dimensions(filepath, model, app);
	//alloc_model_vertices(model, app);
	parse_map(filepath, model, app);
	return (model);
}
