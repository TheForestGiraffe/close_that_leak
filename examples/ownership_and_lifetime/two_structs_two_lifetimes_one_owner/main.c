/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:43:16 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/20 10:53:24 by pecavalc         ###   ########.fr       */
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
	t_item	*item;
	int		ch;

	if (app_init(&app))
		return (1);

	printf("Press Enter to create an item, or 'q' then Enter to quit.\n");

	while (1)
	{
		ch = getchar();
		if (ch == 'q')
			break ;

		item = item_create();
		if (!item)
			break ;

		printf("%s total: %d\n", app.label, app.total);
		item_print(item);

		app.total++;

		item_destroy(item);
	}

	app_destroy(&app);
	return (0);
}
