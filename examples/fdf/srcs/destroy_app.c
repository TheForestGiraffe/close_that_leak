/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_app.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 10:30:08 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fdf.h"
#include "load_map.h"

static void	free_model(t_model **model);
static void	free_model_vertices(t_model **model);
static void	free_projection(t_projection **projection);
static void	free_projection_vertices(t_projection **projection);

void	destroy_app(t_app *app, int exit_code)
{
	free_model(&app->model);
	free_model(&app->model_transformed);
	free_projection(&app->projection);
	if (app->img.img)
	{
		mlx_destroy_image(app->mlx, app->img.img);
		app->img.img = NULL;
	}
	if (app->window)
	{
		mlx_destroy_window(app->mlx, app->window);
		app->window = NULL;
	}
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
		app->mlx = NULL;
	}
	exit(exit_code);
}

static void	free_model(t_model **model)
{
	if (!model || !*model)
		return ;
	free_model_vertices(model);
	free(*model);
	*model = NULL;
}

static void	free_model_vertices(t_model **model)
{
	int	i;

	if (!model || !*model || !(*model)->vertices)
		return ;
	i = (*model)->rows;
	while (i > 0)
		free((*model)->vertices[--i]);
	free((*model)->vertices);
	(*model)->vertices = NULL;
}

static void	free_projection(t_projection **projection)
{
	if (!projection || !*projection)
		return ;
	free_projection_vertices(projection);
	free(*projection);
	*projection = NULL;
}

static void	free_projection_vertices(t_projection **projection)
{
	int	i;

	if (!projection || !*projection || !(*projection)->vertices)
		return ;
	i = (*projection)->rows;
	while (i > 0)
		free((*projection)->vertices[--i]);
	free((*projection)->vertices);
	(*projection)->vertices = NULL;
}
