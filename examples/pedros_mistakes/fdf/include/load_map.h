/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 14:47:24 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_MAP_H
# define LOAD_MAP_H

// Forward declaration of t_app in order to avoid including fdf.h:
typedef struct s_app	t_app;

typedef struct s_3d_vertex
{
	double	x;
	double	y;
	double	z;
}	t_3d_vertex;

typedef struct s_model
{
	int			rows;
	int			columns;
	t_3d_vertex	**vertices;
}	t_model;

t_model	*load_map(char *filepath, t_app *app);
t_model	*alloc_model(t_app *app);
void	alloc_model_vertices(t_model *model, t_app *app);

#endif
