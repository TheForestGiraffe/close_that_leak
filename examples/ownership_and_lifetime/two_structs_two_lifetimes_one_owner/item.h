/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:26:04 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/20 10:32:30 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEM_H
# define ITEM_H

// Per-iteration object

typedef struct s_item
{
	char	**strs;
}			t_item;

// Lifecycle control - to be used by the owner only
t_item	*item_create(void);
void	item_destroy(t_item *item);

// Usage - borrowers can use it
void	item_print(const t_item *item);

#endif