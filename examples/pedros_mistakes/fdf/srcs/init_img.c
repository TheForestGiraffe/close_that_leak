/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:35:03 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/24 14:41:41 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stddef.h>

void	init_img(t_img *img)
{
	img->img = NULL;
	img->address = NULL;
	img->bits_per_pixel = 0;
	img->line_size = 0;
	img->endian = 0;
}
