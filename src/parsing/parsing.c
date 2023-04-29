/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:28:22 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/29 18:45:21 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	parsing(char *filename, t_cube *cube)
{
	cube->file = file_to_tab(filename);
	parse_elements(cube->file, cube);
	parse_description(cube->file, cube);
	return (1);
}
