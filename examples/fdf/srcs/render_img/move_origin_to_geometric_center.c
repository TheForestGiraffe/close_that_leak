/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_origin_to_geometric_center.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:21:56 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 21:20:23 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_map.h"

static double	calc_center_z(t_model *model_transformed);
static void		translate_model(t_model *model_transformed, 
					double dx, double dy, double dz);

void	move_origin_to_geometric_center(t_model *model_transformed)
{
	double	center_x;
	double	center_y;
	double	center_z;

	center_x = (model_transformed->columns - 1) / 2.0;
	center_y = (model_transformed->rows - 1) / 2.0;
	center_z = calc_center_z(model_transformed);
	translate_model(model_transformed, center_x, center_y, center_z);
}

static double	calc_center_z(t_model *model_transformed)
{
	int		j;
	int		i;
	int		z_min;
	int		z_max;

	z_min = model_transformed->vertices[0][0].z;
	z_max = model_transformed->vertices[0][0].z;
	j = 0;
	while (j < model_transformed->rows)
	{
		i = 0;
		while (i < model_transformed->columns)
		{
			if (model_transformed->vertices[j][i].z < z_min)
				z_min = model_transformed->vertices[j][i].z;
			if (model_transformed->vertices[j][i].z > z_max)
				z_max = model_transformed->vertices[j][i].z;
			i++;
		}
		j++;
	}
	return ((z_min + z_max) / 2.0);
}

static void	translate_model(t_model *model_transformed, 
		double dx, double dy, double dz)
{
	int	i;
	int	j;

	j = 0;
	while (j < model_transformed->rows)
	{
		i = 0;
		while (i < model_transformed->columns)
		{
			model_transformed->vertices[j][i].x -= dx;
			model_transformed->vertices[j][i].y -= dy;
			model_transformed->vertices[j][i].z -= dz;
			i++;
		}
		j++;
	}
}
