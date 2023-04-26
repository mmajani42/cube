/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:29:07 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/26 18:25:14 by vimercie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../Libft/inc/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# define WIN_X 3840
# define WIN_Y 2160

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}			t_point;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_color
{
	int		is_set;
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_cube
{
	char		**map;
	void		*mlx;
	void		*mlx_win;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_color		floor;
	t_color		ceiling;
	t_data		img;
	int			max_line_size;
	int			map_size_x;
	int			map_size_y;
	int			win_x;
	int			win_y;
	int			display_status;
}				t_cube;

void	init_parsing(t_cube *cube);

// parsing
int		parsing(char *filename, t_cube *cube);
int		parse_elements(char **file, t_cube *cube);

#endif