
#include "load_map.h"
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_app	app;

	//validate_argc(argc);
	//init_app(&app);
	app.model = load_map(argv[1], &app);
	//app.model_transformed = create_model_transformed(&app);
	//app.projection = create_projection(&app);
	//handle_all_mlx_inits(&app);
	//render_img(&app);
	//mlx_loop(app.mlx);
	return (0);
}
