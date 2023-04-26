/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:29:07 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/26 18:04:30 by mmajani          ###   ########lyon.fr   */
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
	double	x;
	double	y;
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

typedef struct s_player
{
	t_point		pos;
}				t_player;

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
	int			map_size_x;
	int			map_size_y;
	int			win_x;
	int			win_y;
	int			display_status;
}				t_cube;

void	init_parsing(t_cube *cube);

// parsing
int		parsing(char *filename, t_cube *cube);

// draw functions

void	my_mlx_pixel_put(t_cube *cube, int x, int y, int color);
void	clear_image(t_cube *cube);
void	draw_segment(t_cube *cube, t_point a, t_point b, int color);

#endif
