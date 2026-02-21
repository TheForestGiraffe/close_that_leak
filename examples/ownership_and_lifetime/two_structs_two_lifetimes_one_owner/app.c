/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:26:04 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/21 18:14:02 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include <stdlib.h>
#include <string.h>

void	app_init(t_app *app)
{
	app->total = 0;
	app->label = NULL;
	app->version = NULL;
}

int	app_load(t_app *app)
{
	if (!app)
		return (1);

	app->label = strdup("Example 2");
	if (!app->label)
		return (1);

	app->version = strdup("(v1)");
	if (!app->version)
		return (1);

	return (0);
}

void	app_destroy(t_app *app)
{
	if (!app)
		return ;

	free(app->label);
	free(app->version);
	app->label = NULL;
	app->version = NULL;
}

