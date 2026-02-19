/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:33:55 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 21:22:26 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_IMG_INTERNAL_H
# define RENDER_IMG_INTERNAL_H

# include "fdf.h"

typedef struct s_edge {
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
}		t_edge;

void	render_img(t_app *app);
void	erase_img(t_img *img, t_view *view);
void	move_origin_to_geometric_center(t_model *model_transformed);
void	rotate_model(t_app *app);
void	apply_projection(t_app *app);
void	apply_perspective_projection(t_app *app);
void	centralize_view_once(t_view *view, t_projection *projection);
void	centralize_view(t_view *view, t_projection *projection);
void	translate_projection(t_app *app);
void	zoom_projection(t_app *app);
void	render_all_edges(t_app *app);
void	put_pixel(int x, int y, t_view *view, t_img *img);

#endif