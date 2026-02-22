/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 00:02:10 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 20:51:24 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdbool.h>

void	init_view(t_view *view)
{
	view->width = 1024;
	view->height = 768;
	view->zoom = 20;
	view->zoom_step = 1;
	view->shift_x = 0;
	view->shift_y = 0;
	view->translation_step = 10;
	view->color = 0xffbb00;
	view->scale_z = 1;
	view->currently_dragging_with_left_mouse_button = false;
	view->currently_dragging_with_middle_mouse_button = false;
	view->last_mouse_x = 0;
	view->last_mouse_y = 0;
	view->rot_angle_x = 0;
	view->rot_angle_y = 0;
	view->rot_angle_z = 0;
	view->rot_step = 0.01;
	view->projection_type = ISO;
	view->is_auto_rotate_on = false;
}
