/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:03:43 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/04 05:43:52 by vimercie         ###   ########lyon.fr   */
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
		return (print_error("Malloc failed", NULL));
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
				return (print_error("Colors must be numbers in range {0,255}",
						NULL));
			j++;
		}
		n = ft_atoi(tab[i]);
		if (n < 0 || n > 255)
			return (print_error("Color not in range {0,255}", NULL));
		i++;
	}
	if (i != 3)
		return (print_error("Must be 3 colors", NULL));
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
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1')
			return (false);
		if (line[i] == '1')
			wall_on_line = true;
		i++;
	}
	return (wall_on_line);
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
		if (!ft_strchr(" 1", map[y][0]) || !ft_strchr(" 1", map[y][len - 1]))
			return (false);
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == ' ' && !wall_sonar(x, y, map))
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
