/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:26:04 by pecavalc          #+#    #+#             */
/*   Updated: 2026/02/21 18:14:14 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

// Program-lifetime (stack struct, with owned heap field)
// label is freed by app_destroy

typedef struct s_app
{
	char	*label; 
	char	*version;
	int		total;
}			t_app;

// Lifecycle control - to be used by the owner only
void	app_init(t_app *app);
int		app_load(t_app *app);
void	app_destroy(t_app *app);

#endif