/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:54:31 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/06 19:59:17 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

bool	check_file_extension(char *filename, char *format)
{
	char	*extension;

	extension = ft_strnstr(filename, format, ft_strlen(filename));
	if (!extension)
		return (false);
	if (!extension[ft_strlen(format)])
		return (true);
	return (false);
}
