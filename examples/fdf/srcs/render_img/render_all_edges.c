/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:58:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/21 04:41:57 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h> // abs()
#include "fdf.h"
#include "render_img_internal.h"
#include "mlx.h"

void	calc_and_draw_edge(int x, int y, t_app *app, t_edge *edge);
void	draw_edge(t_edge *edge, t_view *view, t_img *img);
void	draw(t_edge *edge, int decision, t_view *view, t_img *img);
int		calc_direction(int start, int end);

void	render_all_edges(t_app *app)
{
	int		y;
	int		x;
	t_edge	edge;

	y = 0;
	while ((y < app->projection->rows))
	{
		x = 0;
		while ((x < app->projection->columns))
		{
			calc_and_draw_edge(x, y, app, &edge);
			x++;
		}
		y++;
	}
}

void	calc_and_draw_edge(int x, int y, t_app *app, t_edge *edge)
{
	edge->x0 = (int)round(app->projection->vertices[y][x].x);
	edge->y0 = (int)round(app->projection->vertices[y][x].y);
	if (x < app->projection->columns - 1)
	{
		edge->x1 = (int)round(app->projection->vertices[y][x + 1].x);
		edge->y1 = (int)round(app->projection->vertices[y][x + 1].y);
		draw_edge(edge, &app->view, &app->img);
	}
	edge->x0 = (int)round(app->projection->vertices[y][x].x);
	edge->y0 = (int)round(app->projection->vertices[y][x].y);
	if (y < app->projection->rows - 1)
	{
		edge->x1 = (int)round(app->projection->vertices[y + 1][x].x);
		edge->y1 = (int)round(app->projection->vertices[y + 1][x].y);
		draw_edge(edge, &app->view, &app->img);
	}
}

void	draw_edge(t_edge *edge, t_view *view, t_img *img)
{
	int	decision;

	edge->dx = abs(edge->x1 - edge->x0);
	edge->dy = abs(edge->y1 - edge->y0);
	decision = edge->dx - edge->dy;
	draw(edge, decision, view, img);
}

void	draw(t_edge *edge, int decision, t_view *view, t_img *img)
{
	int	direction_x;
	int	direction_y;
	int	decision_2;

	direction_x = calc_direction(edge->x0, edge->x1);
	direction_y = calc_direction(edge->y0, edge->y1);
	while (1)
	{
		put_pixel(edge->x0, edge->y0, view, img);
		if (edge->x0 == edge->x1 && edge->y0 == edge->y1)
			break ;
		decision_2 = 2 * decision;
		if (decision_2 > -edge->dy)
		{
			decision -= edge->dy;
			edge->x0 += direction_x;
		}
		if (decision_2 < edge->dx)
		{
			decision += edge->dx;
			edge->y0 += direction_y;
		}
	}
}

int	calc_direction(int start, int end)
{
	if (start < end)
		return (1);
	else
		return (-1);
}
