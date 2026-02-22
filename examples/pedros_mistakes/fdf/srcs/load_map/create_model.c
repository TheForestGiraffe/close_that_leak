/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_model.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/26 12:32:24 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "load_map.h"
#include "load_map_internal.h"

t_model	*create_model(t_app *app)
{
	t_model	*model;

	model = alloc_model(app);
	init_model(model);
	return (model);
}
