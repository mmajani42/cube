/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:49:08 by vimercie          #+#    #+#             */
/*   Updated: 2022/06/09 14:11:12 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	size_t	ft_trim_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] && s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static	size_t	ft_trim_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	while (set[j])
	{
		if (s1[i - 1] == set[j] && i > 0)
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = ft_trim_start(s1, set);
	if (i == ft_strlen(s1))
		return (ft_calloc(sizeof(char), 1));
	j = ft_trim_end(s1, set);
	str = ft_substr(s1, i, j - i);
	if (!str)
		return (NULL);
	str[j - i] = 0;
	return (str);
}
