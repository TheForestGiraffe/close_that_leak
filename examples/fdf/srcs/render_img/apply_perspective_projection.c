/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_perspective_projection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 19:49:31 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "load_map.h"
#include "fdf.h"

void	apply_perspective_projection(t_app *app)
{
	int		i;
	int		j;
	double	x;
	double	y;
	double	depth_factor;

	j = 0;
	while (j < app->model_transformed->rows)
	{
		i = 0;
		while (i < app->model_transformed->columns)
		{
			x = app->model_transformed->vertices[j][i].x;
			y = app->model_transformed->vertices[j][i].y;
			depth_factor = 50 / (50 + app->model_transformed->vertices[j][i].z 
					* app->view.scale_z);
			app->projection->vertices[j][i].x = 
				(x - y) * cos(M_PI / 6) * depth_factor;
			app->projection->vertices[j][i].y = ((x + y) * sin(M_PI / 6) - 
					(app->model_transformed->vertices[j][i].z * 
						app->view.scale_z)) * depth_factor;
			i++;
		}
		j++;
	}
}
