/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:24:38 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/20 20:45:39 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	validate_argc(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("main.c: invalid number of input arguments.", 2);
		exit(EXIT_FAILURE);
	}
}
