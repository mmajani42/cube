/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:54:31 by vimercie          #+#    #+#             */
/*   Updated: 2023/06/04 02:58:55 by vimercie         ###   ########lyon.fr   */
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

char	*get_next_word(char *str)
{
	size_t	len;

	if (!str || ft_is_string_blank(str))
		return (NULL);
	len = 0;
	while (ft_isspace(str[0]) && str[0] != '\n' && str[0])
		str++;
	while (!ft_isspace(str[len]) && str[len])
		len++;
	if (len == 0)
		return (NULL);
	return (ft_strndup(str, len));
}

double	get_player_angle(char direction)
{
	if (direction == 'N')
		return ((double)((3 * PI) / 2));
	if (direction == 'S')
		return ((double)PI / 2);
	if (direction == 'E')
		return ((double)0);
	if (direction == 'W')
		return ((double)PI);
	return (-1);
}

t_point	get_player_pos(char **map)
{
	t_point		res;
	int			x;
	int			y;

	y = 0;
	res.x = -1;
	res.y = -1;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSEW", map[y][x]) != NULL)
			{
				res.x = x;
				res.y = y;
				return (res);
			}
			x++;
		}
		y++;
	}
	if (!map[y])
		print_error("No player found in map description", NULL);
	return (res);
}

void	get_player_coordinates(t_player *p, char **map)
{
	p->pos = get_player_pos(map);
	if (p->pos.x != -1 && p->pos.y != -1)
		p->angle = get_player_angle(map[(int)p->pos.y][(int)p->pos.x]);
}
