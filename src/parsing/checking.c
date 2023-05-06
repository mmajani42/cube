/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:03:43 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/06 22:25:39 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

bool	is_rgb(char **tab)
{
	int	n;
	int	i;
	int	j;

	i = 0;
	if (!tab)
		return (false);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				return (false);
			j++;
		}
		n = ft_atoi(tab[i]);
		if (n < 0 || n > 255)
			return (false);
		i++;
	}
	if (i != 3)
		return (false);
	return (true);
}

bool	is_wall(char *line)
{
	bool	wall_on_line;
	int		i;

	if (!line)
		return (false);
	i = 0;
	wall_on_line = false;
	while ((line[i] == ' ' || line[i] == '1') && line[i])
	{
		if (line[i] == '1')
			wall_on_line = true;
		i++;
	}
	if ((line[i] == '\n' || !line[i]))
		return (wall_on_line);
	return (false);
}

bool	is_valid_map_line(char *line)
{
	int	i;

	i = 0;
	if (ft_is_string_blank(line))
		return (false);
	while (line[i] != '\n' && line[i])
	{
		if (line[i] != '0'
			&& line[i] != '1'
			&& line[i] != ' '
			&& line[i] != 'N'
			&& line[i] != 'S'
			&& line[i] != 'E'
			&& line[i] != 'W')
			return (false);
		i++;
	}
	return (true);
}

bool	is_map_bordered(char **map)
{
	int	len;
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		len = ft_strlen(map[y]);
		if ((map[y][0] != '1' && map[y][0] != ' ')
			|| (map[y][len - 1] != '1' && map[y][len - 1] != ' '))
			return (false);
		x = 0;
		while (map[y][x])
		{
			if ((ft_isspace(map[y][x]) || x == 0)
				&& !wall_sonar(x, y, map))
				return (false);
			x++;
		}
		y++;
	}
	if (!is_wall(map[0]) || !is_wall(map[y - 1]))
		return (false);
	return (true);
}

bool	is_unique_player(char **map)
{
	size_t	n_player;
	int		x;
	int		y;

	y = 0;
	n_player = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSEW", map[y][x]) != NULL)
				n_player++;
			x++;
		}
		y++;
	}
	return (n_player == 1);
}
