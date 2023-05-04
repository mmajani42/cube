/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:55:48 by vimercie          #+#    #+#             */
/*   Updated: 2023/05/04 00:47:35 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

int	set_color(t_color *dest, char *line)
{
	char	**rgb;
	char	*color_str;

	color_str = get_next_word(line);
	if (!color_str)
		return (0);
	rgb = ft_split(color_str, ',');
	if (!rgb)
		return (0);
	if (!is_rgb(rgb))
	{
		free_tab(rgb);
		return (0);
	}
	dest->r = ft_atoi(rgb[0]);
	dest->g = ft_atoi(rgb[1]);
	dest->b = ft_atoi(rgb[2]);
	free(color_str);
	free_tab(rgb);
	return (1);
}

int	set_texture_path(char **dest, char *line)
{
	*dest = get_next_word(line);
	if (!check_file_extension(*dest, ".xpm"))
	{
		free(*dest);
		*dest = NULL;
		return (print_error("Invalid asset format"));
	}
	if (access(*dest, R_OK) == -1)
	{
		perror(*dest);
		free(*dest);
		*dest = NULL;
		return (0);
	}
	return (1);
}

int	parse_elements(char **file, t_cube *cube)
{
	int	set_textures;
	int	i;

	i = 0;
	set_textures = 0;
	while (set_textures < 6 && !is_valid_map_line(file[i]) && file[i])
	{
		if (ft_strncmp(file[i], "NO", 2) == 0 && !cube->no)
			set_textures += set_texture_path(&cube->no, file[i] + 2);
		if (ft_strncmp(file[i], "SO", 2) == 0 && !cube->so)
			set_textures += set_texture_path(&cube->so, file[i] + 2);
		if (ft_strncmp(file[i], "EA", 2) == 0 && !cube->ea)
			set_textures += set_texture_path(&cube->ea, file[i] + 2);
		if (ft_strncmp(file[i], "WE", 2) == 0 && !cube->we)
			set_textures += set_texture_path(&cube->we, file[i] + 2);
		if (ft_strncmp(file[i], "F", 1) == 0 && cube->floor.r == -1)
			set_textures += set_color(&cube->floor, file[i] + 1);
		if (ft_strncmp(file[i], "C", 1) == 0 && cube->ceiling.r == -1)
			set_textures += set_color(&cube->ceiling, file[i] + 1);
		i++;
	}
	if (set_textures < 6)
		return (print_error("Invalid map elements"));
	return (1);
}
