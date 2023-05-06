/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sonar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 05:04:18 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/06 23:06:09 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

bool	check_north_wave(int x, int y, char **map)
{
	int	wave;

	wave = y;
	while (wave > 0 && ft_isspace(map[wave][x]))
		wave--;
	if (map[wave][x] != '1' && !ft_isspace(map[wave][x])
		&& x < (int)ft_strlen(map[wave]))
		return (false);
	return (true);
}

bool	check_south_wave(int x, int y, char **map)
{
	int	wave;

	wave = y;
	while (map[wave])
	{
		if (!ft_isspace(map[wave][x]))
			break ;
		wave++;
	}
	if (!map[wave])
		return (true);
	if (map[wave][x] != '1' && !ft_isspace(map[wave][x])
		&& x < (int)ft_strlen(map[wave]))
		return (false);
	return (true);
}

bool	check_east_wave(int x, int y, char **map)
{
	int	wave;

	wave = x;
	while (map[y][wave] && map[y][wave] == ' ')
		wave++;
	if (map[y][wave] != '1' && !ft_isspace(map[y][wave])
		&& map[y][wave])
		return (false);
	return (true);
}

bool	check_west_wave(int x, int y, char **map)
{
	int	wave;

	wave = x;
	while (wave > 0 && ft_isspace(map[y][wave]))
		wave--;
	if (map[y][wave] != '1' && !ft_isspace(map[y][wave]))
		return (false);
	return (true);
}

bool	wall_sonar(int x, int y, char **map)
{
	if (map[y][x] != ' ')
		return (false);
	if (!check_north_wave(x, y, map)
		|| !check_south_wave(x, y, map)
		|| !check_east_wave(x, y, map)
		|| !check_west_wave(x, y, map))
		return (false);
	return (true);
}
