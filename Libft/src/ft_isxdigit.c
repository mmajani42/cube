/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:58:37 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/29 17:01:32 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

bool	ft_isxdigit(int c)
{
	if ((c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F')
		|| ft_isdigit(c))
		return (true);
	return (false);
}
