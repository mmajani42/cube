/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:13:43 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/29 16:13:43 by mmajani          ###   ########lyon.fr   */
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
	cube->off_x = 0;
	cube->off_y = 0;
}

void	set_tile_size(t_cube *cube)
{
	int		lines;
	int		longest;
	double	ratio_y;
	double	ratio_x;

	lines = cube->map_height;
	longest = cube->max_line_size - 1;
	ratio_x = WIN_X / longest;
	ratio_y = WIN_Y / lines;
	if (ratio_x > ratio_y)
		cube->ts = ratio_y;
	if (ratio_x <= ratio_y)
		cube->ts = ratio_y;
	cube->ts = cube->ts * 0.5;
	cube->off_x = (WIN_X - (longest * cube->ts)) / 2;
	cube->off_y = (WIN_Y - (lines * cube->ts)) / 2;
}

void	set_offset(t_cube *cube)
{
	t_point	mid;
	double	off_x;
	double	off_y;

	off_x = 0;
	off_y = 0;
	mid.x = 0;
	mid.y = 0;
	
	printf("offx=%.2f\noffy=%.2f\n", cube->off_x, cube->off_y);
}
