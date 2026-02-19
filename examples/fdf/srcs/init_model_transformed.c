/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_model_transformed.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 10:38:55 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "load_map.h"

void	init_model_transformed(t_model *model_transformed, t_model *model)
{
	model_transformed->rows = model->rows;
	model_transformed->columns = model->columns;
	model_transformed->vertices = NULL;
}
