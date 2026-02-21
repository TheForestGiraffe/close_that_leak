/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:43:16 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/21 18:16:27 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#include "app.h"

int	main(void)
{
	t_app	app;
	t_item	item;
	int		ch;

	app_init(&app);

	if (app_load(&app))
	{
		app_destroy(&app);
		return (1);
	}

	printf("%s %s\n\n", app.label, app.version);
	printf("Press Enter to create an item, or 'q' then Enter to quit.\n ");

   while (1)
	{
		ch = getchar();
		if (ch == 'q')
			break ;
		if (ch != '\n')
			continue ;

		item_init(&item);
		
		if (item_load(&item))
		{
			item_destroy(&item);
			break ;
		}

		printf("Total: %d\n", app.total);
		item_print(&item);

		app.total++;

		item_destroy(&item);
	}

	printf("Exiting: %s %s\n", app.label, app.version);
	app_destroy(&app);

	return (0);
}
