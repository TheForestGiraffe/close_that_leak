/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.3.syntax_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kschmitt <kschmitt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:58:07 by kschmitt          #+#    #+#             */
/*   Updated: 2026/01/05 12:44:40 by kschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	final_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!final_str)
		return (NULL);
	i = 0;
	while (s1 && (len_s1 > i))
	{
		final_str[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		final_str[i] = s2[i - len_s1];
		i++;
	}
	final_str[i] = '\0';
	return (final_str);
}

int	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

char	*blackout_quoted_content(char *str)
{
	char	*copy;
	char	quot_mark;
	int		i;

	copy = ft_strjoin("", str);
	quot_mark = 0;
	i = -1;
	while (copy[++i])
	{
		if (is_quote(copy[i]))
		{
			quot_mark = copy[i];
			i++;
			while (copy[i + 1] && copy[i] != quot_mark)
			{
				copy[i] = 48;
				i++;
			}
		}
	}
	return (copy);
}
