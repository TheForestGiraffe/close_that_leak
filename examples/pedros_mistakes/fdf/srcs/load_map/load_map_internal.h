/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/26 12:37:14 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_MAP_INTERNAL_H
# define LOAD_MAP_INTERNAL_H

# include "load_map.h"

void	init_model(t_model *model);
void	parse_map_dimensions(char *filepath, t_model *model, t_app *app);
void	parse_map(char *filepath, t_model *model, t_app *app);
int		try_open(char *filepath, t_app *app);
char	*try_get_next_line(int fd, t_app *app);
char	**try_ft_split(char *line, t_app *app);
t_model	*create_model(t_app *app);

#endif