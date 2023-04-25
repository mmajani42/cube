/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:30:28 by vimercie          #+#    #+#             */
/*   Updated: 2022/06/09 14:11:12 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	int	ft_intlen(int n)
{
	int		len;
	size_t	nb;

	len = 0;
	nb = n;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		nb = -n;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	while (n > 9)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	str[len] = n % 10 + '0';
	return (str);
}
