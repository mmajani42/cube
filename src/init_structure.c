/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:13:43 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/04 18:26:37 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	init_cube(t_cube *cube)
{
	cube->map = NULL;
	cube->file = NULL;
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
	cube->ts = 0;
	cube->map_height = 0;
	cube->max_line_size = 0;
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
	cube->ts = 64;
	cube->off_x = (WIN_X - (longest * cube->ts)) / 2;
	cube->off_y = (WIN_Y - (lines * cube->ts)) / 2;
}
