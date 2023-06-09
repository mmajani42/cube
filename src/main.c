/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:21:46 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/07 13:04:18 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	main(int ac, char **av)
{
	t_cube	cube;

	if (ac != 2)
		return (print_error("This program takes only 1 argument", NULL));
	init_mlx(&cube);
	if (!parsing(av[1], &cube))
		return (close_cube(&cube));
	set_player(&cube);
	get_map_ts(&cube);
	mlx_hook(cube.mlx_win, 3, 1L << 1, &key_release_events, &cube);
	mlx_hook(cube.mlx_win, 2, 1L << 0, &key_pressed_events, &cube);
	mlx_hook(cube.mlx_win, 17, 1L << 0, &close_cube, &cube);
	mlx_loop_hook(cube.mlx, cube_loop, &cube);
	mlx_loop(cube.mlx);
	return (0);
}
