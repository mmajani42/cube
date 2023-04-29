/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:49:14 by vimercie          #+#    #+#             */
/*   Updated: 2023/04/29 14:22:23 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

char	*get_next_word(char *str)
{
	size_t	len;

	if (!str)
		return (NULL);
	len = 0;
	while (ft_isspace(str[0]) && str[0] != '\n' && str[0])
		str++;
	while (!ft_isspace(str[len]) && str[len])
		len++;
	if (len == 0)
		return (NULL);
	return (ft_strndup(str, len));
}
