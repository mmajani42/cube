/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:55:48 by vimercie          #+#    #+#             */
/*   Updated: 2023/04/29 14:51:57 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	set_texture_path(char **dest, char *line)
{
	*dest = get_next_word(line);
	if (access(*dest, R_OK) == -1)
	{
		perror("access");
		free(*dest);
		*dest = NULL;
		return (0);
	}
	return (1);
}

int	set_color(t_color *dest, char *line)
{
	char	**rgb;
	char	*color_str;

	color_str = get_next_word(line);
	if (!color_str)
		return (0);
	rgb = ft_split(color_str, ',');
	if (!is_rgb(rgb))
		return (0);
	dest->r = ft_atoi(rgb[0]);
	dest->g = ft_atoi(rgb[1]);
	dest->b = ft_atoi(rgb[2]);
	free(color_str);
	free_tab(rgb);
	return (1);
}

int	parse_elements(char **file, t_cube *cube)
{
	int	set_textures;

	set_textures = 0;
	while (file[0] && set_textures < 6)
	{
		if (ft_strncmp(file[0], "NO", 2) == 0 && !cube->no)
			set_textures += set_texture_path(&cube->no, file[0] + 2);
		if (ft_strncmp(file[0], "SO", 2) == 0 && !cube->so)
			set_textures += set_texture_path(&cube->so, file[0] + 2);
		if (ft_strncmp(file[0], "EA", 2) == 0 && !cube->ea)
			set_textures += set_texture_path(&cube->ea, file[0] + 2);
		if (ft_strncmp(file[0], "WE", 2) == 0 && !cube->we)
			set_textures += set_texture_path(&cube->we, file[0] + 2);
		if (ft_strncmp(file[0], "F", 1) == 0)
			set_textures += set_color(&cube->floor, file[0] + 1);
		if (ft_strncmp(file[0], "C", 1) == 0)
			set_textures += set_color(&cube->ceiling, file[0] + 1);
		file++;
	}
	if (set_textures < 6)
		return (0);
	return (1);
}
