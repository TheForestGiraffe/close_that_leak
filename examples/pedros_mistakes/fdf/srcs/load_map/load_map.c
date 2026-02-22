/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 10:51:04 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "load_map.h"
#include "load_map_internal.h"

t_model	*load_map(char *filepath, t_app *app)
{
	t_model	*model;

	model = create_model(app);
	parse_map_dimensions(filepath, model, app);
	alloc_model_vertices(model, app);
	parse_map(filepath, model, app);
	return (model);
}
