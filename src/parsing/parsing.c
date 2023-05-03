/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:28:22 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/04 00:02:58 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	parsing(char *filename, t_cube *cube)
{
	cube->file = file_to_tab(filename);
	if (!cube->file)
		return (0);
	if (!parse_elements(cube->file, cube)
		|| !parse_description(cube->file, cube))
		return (0);
	return (1);
}
