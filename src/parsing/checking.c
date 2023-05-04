/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:03:43 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/04 00:57:40 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

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
