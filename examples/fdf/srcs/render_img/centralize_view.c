/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centralize_view.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:22:09 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 11:16:23 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	centralize_x(t_view *view, t_projection *projection);
static int	centralize_y(t_view *view, t_projection *projection);

void	centralize_view(t_view *view, t_projection *projection)
{
	view->shift_x = centralize_x(view, projection);
	view->shift_y = centralize_y(view, projection);
}

static int	centralize_x(t_view *view, t_projection *projection)
{
	int		i;
	int		j;
	double	x_min;
	double	x_max;

	x_min = projection->vertices[0][0].x;
	x_max = projection->vertices[0][0].x;
	j = 0;
	while (j < projection->rows)
	{
		i = 0;
		while (i < projection->columns)
		{
			if (projection->vertices[j][i].x < x_min)
				x_min = projection->vertices[j][i].x;
			if (projection->vertices[j][i].x > x_max)
				x_max = projection->vertices[j][i].x;
			i++;
		}
		j++;
	}
	return ((view->width / 2) - ((x_min + x_max) / 2.0));
}

static int	centralize_y(t_view *view, t_projection *projection)
{
	int		i;
	int		j;
	double	y_min;
	double	y_max;

	y_min = projection->vertices[0][0].y;
	y_max = projection->vertices[0][0].y;
	j = 0;
	while (j < projection->rows)
	{
		i = 0;
		while (i < projection->columns)
		{
			if (projection->vertices[j][i].y < y_min)
				y_min = projection->vertices[j][i].y;
			if (projection->vertices[j][i].y > y_max)
				y_max = projection->vertices[j][i].y;
			i++;
		}
		j++;
	}
	return ((view->height / 2) - ((y_min + y_max) / 2.0));
}
