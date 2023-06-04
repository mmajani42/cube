/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:21:13 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/04 01:39:10 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	print_error(char *error, char *token)
{
	ft_putstr_fd("Error\n", 2);
	if (token != NULL)
	{
		ft_putstr_fd(token, 2);
		ft_putstr_fd(": ", 2);
	}
	if (!error)
		return (0);
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}
