/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_description.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:08:01 by vimercie          #+#    #+#             */
/*   Updated: 2023/04/29 16:43:02 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	parse_description(char **file, t_cube *cube)
{
	while (!is_valid_map_line(file[0]) && file[0])
		file++;
	if (!file[0])
		return (print_error("No map description"));
	while (file[cube->map_height])
	{
		if (!is_valid_map_line(file[cube->map_height]))
			return (print_error("Invalid map description"));
		cube->map_height++;
	}
	cube->max_line_size = get_max_line_size(cube->map);
	cube->map = file;
	return (1);
}
