/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_projection_vertices.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:44:52 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 10:58:21 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"

void	alloc_projection_vertices(t_projection *projection, t_app *app)
{
	int	y;

	projection->vertices = malloc(projection->rows * 
			sizeof(t_2d_vertex *));
	if (!projection->vertices)
	{
		perror("alloc_projection_vertices: 1st malloc failed.");
		destroy_app(app, EXIT_FAILURE);
	}
	y = 0;
	while (y < projection->rows)
	{
		projection->vertices[y] = 
			malloc(projection->columns * sizeof(t_2d_vertex));
		if (!projection->vertices[y])
		{
			while (y > 0)
				free(projection->vertices[--y]);
			perror("alloc_projection_vertices: 2nd malloc failed.");
			destroy_app(app, EXIT_FAILURE);
		}
		y++;
	}
}
