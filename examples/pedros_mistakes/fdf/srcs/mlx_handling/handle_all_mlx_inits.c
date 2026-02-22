/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_all_mlx_inits.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:14:59 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 15:18:53 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_handling_internal.h"

void	handle_all_mlx_inits(t_app *app)
{
	init_mlx(app);
	init_mlx_window(app);
	register_mlx_hooks(app);
	init_mlx_img(app->mlx, &app->view, &app->img);
}
