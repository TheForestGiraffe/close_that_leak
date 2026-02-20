/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:26:04 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/20 10:39:19 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include <stdlib.h>
#include <string.h>

int	app_init(t_app *app)
{
	app->total = 0;
	app->label = strdup("APP");
	if (!app->label)
		return (1);
	return (0);
}

void	app_destroy(t_app *app)
{
	free(app->label);
}
