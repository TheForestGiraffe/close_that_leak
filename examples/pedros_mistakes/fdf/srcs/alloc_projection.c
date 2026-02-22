/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:44:52 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 10:28:23 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"

t_projection	*alloc_projection(t_app *app)
{
	t_projection	*projection;

	projection = (t_projection *)malloc(sizeof(t_projection));
	if (!projection)
	{
		perror("alloc_projection: malloc failed");
		destroy_app(app, EXIT_FAILURE);
	}
	return (projection);
}
