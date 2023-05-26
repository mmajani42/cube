/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:27:22 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/26 17:33:35 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	key_release_events(int keycode, t_cube *cube)
{
	if (keycode == W)
		cube->key_w = 0;
	else if (keycode == S)
		cube->key_s = 0;
	if (keycode == A)
		cube->key_a = 0;
	else if (keycode == D)
		cube->key_d = 0;
	return (0);
}

int	key_pressed_events(int keycode, t_cube *cube)
{
	if (keycode == ESC || keycode == X)
	{
		mlx_destroy_window(cube->mlx, cube->mlx_win);
		exit(1);
	}
	if (keycode == W)
		cube->key_w = 1;
	else if (keycode == S)
		cube->key_s = 1;
	if (keycode == A)
		cube->key_a = 1;
	else if (keycode == D)
		cube->key_d = 1;
	return (0);
}
