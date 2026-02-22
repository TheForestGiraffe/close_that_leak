/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centralize_view_once.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:55:48 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 10:13:22 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render_img_internal.h"

void	centralize_view_once(t_view *view, t_projection *projection)
{
	if ((view->shift_x == 0) && (view->shift_y == 0))
		centralize_view(view, projection);
}
