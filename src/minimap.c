/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:38:01 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/26 18:14:26 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	set_offset(t_cube *cube)
{
	cube->ts = 100;
	cube->off_y = cube->ts / 2;
	cube->off_x = ((WIN_X / 5) * 4) - 1;
}

void	malloc_minimap(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	cube->minimap = malloc(sizeof(t_point *) * cube->map_height);
	while (i < cube->map_height)
	{
		j = 0;
		cube->minimap[i] = malloc(sizeof(t_point) * cube->map_width);
		while (j < cube->map_width)
		{
			cube->minimap[i][j].y = 0;
			cube->minimap[i][j].x = 0;
			j++;
		}
		i++;
	}
}

void	set_minimap(t_cube *cube)
{
	int	x;
	int	y;

	malloc_minimap(cube);
	y = 0;
	x = 0;
	while (y < cube->map_height)
	{
		while (x < cube->map_width)
		{
			cube->minimap[y][x].x = (x * cube->ts);
			cube->minimap[y][x].y = (y * cube->ts);
			x++;
		}
		x = 0;
		y++;
	}
	set_offset(cube);
}


void	draw_map(t_cube *cube)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < cube->map_height)
	{
		while (x <= cube->map_width)
		{
			if (cube->map[y][x] == '1')
				draw_square(cube, cube->minimap[y][x].x, cube->minimap[y][x].y);
			x++;
		}
		y++;
		x = 0;
	}
}
