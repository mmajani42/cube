/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:21:46 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/29 17:01:53 by mmajani          ###   ########lyon.fr   */
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

int	key_events(int keycode, t_cube *cube)
{
	printf("keycode =%d\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_window(cube->mlx, cube->mlx_win);
		exit(1);
	}
	// if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
	// 	translate_view(cube, keycode);
	// if (keycode == Q || keycode == E)
	// 	scale_points(cube, keycode);
	// if (keycode == 87 || keycode == 91)
	// 	rotate_x_axis(cube, keycode);
	// if (keycode == 86 || keycode == 88)
	// 	rotate_y_axis(cube, keycode);
	// if (keycode == 89 || keycode == 92)
	// 	rotate_z_axis(cube, keycode);
	display_handling(cube);
	return (0);
}

void	print_tab(char **tab)
{	
	int	x;

	x = 0;
	while (tab[x])
	{
		printf("%s", tab[x]);
		x++;
	}
}

int	main(int ac, char **av)
{
	t_cube	cube;

	if (ac != 2)
		return (0);
	init_mlx(&cube);
	init_parsing(&cube);
	parsing(av[1], &cube);
	// set_tile_size(&cube);
	//print_tab(cube.map);
	display_handling(&cube);
	mlx_key_hook(cube.mlx_win, key_events, &cube);
	mlx_loop(cube.mlx);
	return (0);
}
