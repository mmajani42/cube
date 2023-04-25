/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:01:07 by vimercie          #+#    #+#             */
/*   Updated: 2023/02/20 10:38:31 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (n < len)
		res = ft_calloc(n + 1, sizeof(char));
	else
		res = ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s[i] && i < n)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
