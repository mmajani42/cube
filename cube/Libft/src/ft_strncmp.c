/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:07:11 by vimercie          #+#    #+#             */
/*   Updated: 2022/06/09 14:11:12 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strncmp(const char	*s1, const char *s2, size_t n)
{
	size_t	ptr_n;
	int		diff;
	int		i;

	i = 0;
	ptr_n = n;
	if (n == 0)
		return (0);
	while (ptr_n != 0)
	{	
		if (s1[i] || s2[i])
		{
			diff = (unsigned char)s1[i] - (unsigned char)s2[i];
			if (diff != 0)
				return (diff);
			i++;
		}
		ptr_n--;
	}
	return (0);
}
