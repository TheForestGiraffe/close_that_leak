/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_on_button_release.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 20:59:17 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "fdf.h"
#include "render_img.h"
#include "mlx_handling_internal.h"

static void	handle_rmb_release(t_app *app);
static void	handle_mmb_release(t_app *app);

int	handle_on_button_release(int button, int x, int y, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	app->view.last_mouse_x = x;
	app->view.last_mouse_y = y;
	if (button == RIGHT_MOUSE_BUTTON)
		handle_rmb_release(app);
	if (button == MIDDLE_MOUSE_BUTTON)
		handle_mmb_release(app);
	return (0);
}

static void	handle_rmb_release(t_app *app)
{
	app->view.currently_dragging_with_left_mouse_button = false;
}

static void	handle_mmb_release(t_app *app)
{
	app->view.currently_dragging_with_middle_mouse_button = false;
}
