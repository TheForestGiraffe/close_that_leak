/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 10:35:24 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"
#include "load_map.h"

t_model	*alloc_model(t_app *app)
{
	t_model	*model;

	model = (t_model *)malloc(sizeof(t_model));
	if (!model)
	{
		perror("alloc_model: malloc failed.");
		destroy_app(app, EXIT_FAILURE);
	}
	return (model);
}
