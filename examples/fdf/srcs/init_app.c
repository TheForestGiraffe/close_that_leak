/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:35:03 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/26 13:10:23 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stddef.h>

void	init_app(t_app *app)
{
	app->mlx = NULL;
	app->window = NULL;
	init_img(&app->img);
	init_view(&app->view);
	app->model = NULL;
	app->model_transformed = NULL;
	app->projection = NULL;
}
