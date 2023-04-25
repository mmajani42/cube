/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:16:28 by vimercie          #+#    #+#             */
/*   Updated: 2022/06/09 14:11:12 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n)
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((unsigned char *)s);
		s++;
		n--;
	}
	return (NULL);
}
