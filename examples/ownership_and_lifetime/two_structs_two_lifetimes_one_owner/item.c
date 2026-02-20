/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:26:04 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/20 10:53:10 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "item.h"

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
			i++;
		}
		free(item->strs);
	}
	free(item);
}

t_item	*item_create(void)
{
	t_item	*item;

	item = calloc(1, sizeof(*item));
	if (!item)
		return (NULL);

	item->strs = calloc(3, sizeof(char *));
	if (!item->strs)
		return (item_destroy(item), NULL);

	item->strs[0] = strdup("first item");
	if (!item->strs[0])
		return (item_destroy(item), NULL);

	item->strs[1] = strdup("second item");
	if (!item->strs[1])
		return (item_destroy(item), NULL);

	return (item);
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
