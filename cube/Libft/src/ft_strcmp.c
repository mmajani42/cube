/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:07:11 by vimercie          #+#    #+#             */
/*   Updated: 2023/04/20 16:28:16 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	int		diff;

	i = 0;
	while (s1[i] || s2[i])
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}
