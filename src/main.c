/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:21:46 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/26 13:46:47 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

void	init_mlx(t_cube *cube)
{
	cube->win_x = 3840;
	cube->win_y = 2160;
	cube->mlx = mlx_init();
	cube->mlx_win = mlx_new_window(cube->mlx, cube->win_x,
			cube->win_y, "Hello world!");
	cube->img.img = mlx_new_image(cube->mlx, cube->win_x, cube->win_y);
	cube->img.addr = mlx_get_data_addr(cube->img.img,
			&cube->img.bits_per_pixel, &cube->img.line_length, &cube->img.endian);
	cube->img.bits_per_pixel /= 8;
	cube->display_status = 1;
}

int	main(int ac, char **av)
{
	t_cube	cube;

	(void)ac;
	init_parsing(&cube);
	// init_mlx(&cube);
	parsing(av[1], &cube);
	return (0);
}
