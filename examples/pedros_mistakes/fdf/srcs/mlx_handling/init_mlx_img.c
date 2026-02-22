/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:55:28 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/26 12:53:39 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	init_mlx_img(void *mlx, t_view *view, t_img *img)
{
	img->img = mlx_new_image(mlx, view->width, view->height);
	img->address = mlx_get_data_addr(img->img, &img->bits_per_pixel, 
			&img->line_size, &img->endian);
}
