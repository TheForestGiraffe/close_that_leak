/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:44:52 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 09:39:32 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void	init_projection(t_projection *projection, t_model *model_transformed)
{
	projection->rows = model_transformed->rows;
	projection->columns = model_transformed->columns;
	projection->vertices = NULL;
}
