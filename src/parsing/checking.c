/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:03:43 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/04 18:22:18 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

bool	check_file_extension(char *filename, char *format)
{
	char	*extension;

	extension = ft_strnstr(filename, format, ft_strlen(filename));
	if (!extension)
		return (false);
	if (!extension[ft_strlen(format)])
		return (true);
	return (false);
}

bool	is_rgb(char **tab)
{
	int	n;
	int	i;
	int	j;

	i = 0;
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
	if ((line[i] == '\n' || !line[i]) && wall_on_line == true)
		return (true);
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
		if ((line[i] != '0'
				&& line[i] != '1'
				&& line[i] != ' '
				&& line[i] != 'N'
				&& line[i] != 'S'
				&& line[i] != 'E'
				&& line[i] != 'W')
			|| ((line[i] == 'N'
					|| line[i] == 'S'
					|| line[i] == 'E'
					|| line[i] == 'W')
				&& ((line[i + 1] != '0'
						&& line[i + 1] != '1')
					|| !line[i + i])))
			return (false);
		i++;
	}
	return (true);
}

bool	is_map_bordered(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		// scanner les murs orientés 'N' et 'S' qui font face à du vide;
		// -> formater la map pour que chaque ligne fasse max_line_size de longueur, copier avec ft_strlcpy() puis remplir l'espace vide de '0' avec memset().
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
