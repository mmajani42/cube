/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:21:46 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/26 17:17:56 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	key_events(int keycode, t_cube *cube)
{
	if (keycode == ESC || keycode == X)
	{
		mlx_destroy_window(cube->mlx, cube->mlx_win);
		exit(1);
	}
	if (keycode == W || keycode == A || keycode == S || keycode == D
		|| keycode == Z)
		change_player_vector(cube, keycode);
	return (0);
}

void	print_tab(char **tab)
{	
	int	x;

	x = 0;
	while (tab[x])
	{
		dprintf(1, "%s", tab[x]);
		x++;
	}
}

int	main(int ac, char **av)
{
	t_cube	cube;

	if (ac != 2)
		return (print_error("This program takes only 1 argument"));
	if (!parsing(av[1], &cube))
		return (0);
	set_player(&cube);
	init_mlx(&cube);
	mlx_hook(cube.mlx_win, 2, 1L << 0, &key_events, &cube);
	mlx_loop_hook(cube.mlx, display_handling, &cube);
	mlx_loop(cube.mlx);
	cube_tester(&cube);
	free_cube(&cube);
	return (0);
}
