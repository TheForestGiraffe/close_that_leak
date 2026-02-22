/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_model.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:47:58 by plima             #+#    #+#             */
/*   Updated: 2025/09/26 13:02:40 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static void	rotate_vertex_around_x(int i, int j, t_app *app);
static void	rotate_vertex_around_y(int i, int j, t_app *app);
static void	rotate_vertex_around_z(int i, int j, t_app *app);

void	rotate_model(t_app *app)
{
	int	i;
	int	j;

	j = 0;
	while (j < app->model->rows)
	{
		i = 0;
		while (i < app->model->columns)
		{
			rotate_vertex_around_x(i, j, app);
			rotate_vertex_around_y(i, j, app);
			rotate_vertex_around_z(i, j, app);
			i++;
		}
		j++;
	}
}

static void	rotate_vertex_around_x(int i, int j, t_app *app)
{
	double	y;
	double	z;
	double	theta;

	y = app->model_transformed->vertices[j][i].y;
	z = app->model_transformed->vertices[j][i].z;
	theta = app->view.rot_angle_x;
	app->model_transformed->vertices[j][i].y = y * cos(theta) - z * sin(theta);
	app->model_transformed->vertices[j][i].z = y * sin(theta) + z * cos(theta);
}

static void	rotate_vertex_around_y(int i, int j, t_app *app)
{
	double	x;
	double	z;
	double	theta;

	x = app->model_transformed->vertices[j][i].x;
	z = app->model_transformed->vertices[j][i].z;
	theta = app->view.rot_angle_y;
	app->model_transformed->vertices[j][i].x = x * cos(theta) + z * sin(theta);
	app->model_transformed->vertices[j][i].z = -x * sin(theta) + z * cos(theta);
}

static void	rotate_vertex_around_z(int i, int j, t_app *app)
{
	double	x;
	double	y;
	double	theta;

	x = app->model_transformed->vertices[j][i].x;
	y = app->model_transformed->vertices[j][i].y;
	theta = app->view.rot_angle_z;
	app->model_transformed->vertices[j][i].x = x * cos(theta) - y * sin(theta);
	app->model_transformed->vertices[j][i].y = x * sin(theta) + y * cos(theta);
}
