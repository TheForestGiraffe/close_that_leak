/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_on_mouse_move.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:27:19 by plima             #+#    #+#             */
/*   Updated: 2025/09/25 20:55:53 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render_img.h"

int	handle_on_mouse_move(int x, int y, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (app->view.currently_dragging_with_left_mouse_button)
	{
		app->view.rot_angle_z -= (x - app->view.last_mouse_x) * 
			app->view.rot_step;
		app->view.rot_angle_x -= (y - app->view.last_mouse_y) * 
			app->view.rot_step;
		app->view.last_mouse_x = x;
		app->view.last_mouse_y = y;
		render_img(app);
	}
	else if (app->view.currently_dragging_with_middle_mouse_button)
	{
		app->view.shift_x += (x - app->view.last_mouse_x) * 
			(app->view.translation_step / 10);
		app->view.shift_y += (y - app->view.last_mouse_y) * 
			(app->view.translation_step / 10);
		app->view.last_mouse_x = x;
		app->view.last_mouse_y = y;
		render_img(app);
	}
	return (0);
}
