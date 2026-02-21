/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:26:04 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/21 17:58:50 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "item.h"


void	item_init(t_item *item)
{
	item->strs = NULL;
}

int	item_load(t_item *item)
{
	item->strs = calloc(3, sizeof(char *));
	if (!item->strs)
		return (1);

	item->strs[0] = strdup("first item");
	if (!item->strs[0])
		return (1);

	item->strs[1] = strdup("second item");
	if (!item->strs[1])
		return (1);

	return (0);
}

void	item_destroy(t_item *item)
{
	int	i;

	if (!item)
		return ;

	if (item->strs)
	{
		i = 0;
		while (item->strs[i])
		{
			free(item->strs[i]);
			item->strs[i] = NULL;
			i++;
		}
		free(item->strs);
		item->strs = NULL;
	}
}

// Usage (borrows)

void	item_print(const t_item *item)
{
	int	i;

	i = 0;
	while (item->strs[i])
	{
		printf("[%s]", item->strs[i]);
		printf("\n");
		i++;
	}
	printf("\n");
}
