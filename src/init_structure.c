/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:13:43 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/29 14:53:27 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	init_parsing(t_cube *cube)
{
	cube->no = NULL;
	cube->so = NULL;
	cube->we = NULL;
	cube->ea = NULL;
	cube->floor.r = -1;
	cube->floor.g = -1;
	cube->floor.b = -1;
	cube->ceiling.r = -1;
	cube->ceiling.g = -1;
	cube->ceiling.b = -1;
	cube->ts = 100;
	cube->map_height = 0;
}
