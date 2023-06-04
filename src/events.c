/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:27:22 by mmajani           #+#    #+#             */
/*   Updated: 2023/06/04 02:14:37 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube.h"

int	key_release_events(int keycode, t_cube *cube)
{
	if (keycode == W)
		cube->key_w = 0;
	if (keycode == S)
		cube->key_s = 0;
	if (keycode == A)
		cube->key_a = 0;
	if (keycode == D)
		cube->key_d = 0;
	if (keycode == LEFT)
		cube->key_left = 0;
	if (keycode == RIGHT)
		cube->key_right = 0;
	return (0);
}

int	key_pressed_events(int keycode, t_cube *cube)
{
	if (keycode == ESC)
		close_cube(cube);
	if (keycode == W)
		cube->key_w = 1;
	else if (keycode == S)
		cube->key_s = 1;
	if (keycode == A)
		cube->key_a = 1;
	else if (keycode == D)
		cube->key_d = 1;
	if (keycode == LEFT)
		cube->key_left = 1;
	else if (keycode == RIGHT)
		cube->key_right = 1;
	return (0);
}
