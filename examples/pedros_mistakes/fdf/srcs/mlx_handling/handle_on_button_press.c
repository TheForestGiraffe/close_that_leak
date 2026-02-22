/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_on_button_press.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/26 13:17:40 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "fdf.h"
#include "render_img.h"
#include "mlx_handling_internal.h"

static void	handle_wheel_scroll(int button, t_app *app);
static void	handle_rmb_press(t_app *app);
static void	handle_mmb_press(t_app *app);

int	handle_on_button_press(int button, int x, int y, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	app->view.last_mouse_x = x;
	app->view.last_mouse_y = y;
	if ((button == MOUSE_WHEEL_DOWN_BUTTON) | (button == MOUSE_WHEEL_UP_BUTTON))
		handle_wheel_scroll(button, app);
	if (button == RIGHT_MOUSE_BUTTON)
		handle_rmb_press(app);
	if (button == MIDDLE_MOUSE_BUTTON)
		handle_mmb_press(app);
	return (0);
}

static void	handle_wheel_scroll(int button, t_app *app)
{
	if (button == MOUSE_WHEEL_DOWN_BUTTON)
	{
		app->view.zoom -= app->view.zoom_step;
		if (app->view.zoom < 0.1)
			app->view.zoom = 0.1;
	}
	if (button == MOUSE_WHEEL_UP_BUTTON)
		app->view.zoom += app->view.zoom_step;
	render_img(app);
}

static void	handle_rmb_press(t_app *app)
{
	app->view.currently_dragging_with_left_mouse_button = true;
}

static void	handle_mmb_press(t_app *app)
{
	app->view.currently_dragging_with_middle_mouse_button = true;
}
