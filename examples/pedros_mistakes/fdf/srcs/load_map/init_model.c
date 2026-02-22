/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 10:35:44 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "load_map.h"

void	init_model(t_model *model)
{
	model->rows = 0;
	model->columns = 0;
	model->vertices = NULL;
}
