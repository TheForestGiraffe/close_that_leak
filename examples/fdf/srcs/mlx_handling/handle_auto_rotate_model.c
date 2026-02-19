/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_auto_rotate_model.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:04:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 20:26:08 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render_img_internal.h"

int	handle_auto_rotate_model(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (app->view.is_auto_rotate_on)
	{
		app->view.rot_angle_z += app->view.rot_step / 5;
		render_img(app);
	}
	return (0);
}
