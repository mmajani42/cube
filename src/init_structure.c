/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:13:43 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/25 23:10:39 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	init_cube(t_cube *cube)
{
	cube->map = NULL;
	cube->file = NULL;
	cube->no->path = NULL;
	cube->so->path = NULL;
	cube->we->path = NULL;
	cube->ea->path = NULL;
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
	cube->fov_radian = FOV * PI / 180;
}

void	init_asset(t_asset *asset, void *mlx)
{
	asset->width = 0;
	asset->height = 0;
	asset->img.img = mlx_xpm_file_to_image(mlx, asset->path,
			&asset->width, &asset->height);
	asset->img.addr = mlx_get_data_addr(asset->img.img,
			&asset->img.bits_per_pixel,
			&asset->img.line_length,
			&asset->img.endian);
}

void	set_tile_size(t_cube *cube)
{
	int		lines;
	int		longest;
	double	ratio_y;
	double	ratio_x;

	lines = cube->map_height;
	longest = cube->max_line_size;
	ratio_x = WIN_X / longest;
	ratio_y = WIN_Y / lines;
	if (ratio_x > ratio_y)
		cube->ts = ratio_y;
	if (ratio_x <= ratio_y)
		cube->ts = ratio_y;
	// cube->off_x = (WIN_X - (longest * cube->ts)) / 2;
	// cube->off_y = (WIN_Y - (lines * cube->ts)) / 2 + cube->ts / 2;
	cube->ts = 64;
}
