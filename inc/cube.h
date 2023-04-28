/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:29:07 by mmajani           #+#    #+#             */
/*   Updated: 2023/04/28 15:34:03 by mmajani          ###   ########lyon.fr   */
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

# define W 			119
# define A 			97
# define S 			115
# define D 			100
# define O 			111
# define P 			112
# define R 			114
# define G 			103
# define B 			98
# define ESC		65307
# define TAB		48
# define SPACE		49
# define PLUS		65451
# define MINUS		65454
# define LEFT		65361
# define RIGHT		65363
# define DOWN		65364
# define UP			65362

typedef struct s_point
{
	float	x;
	float	y;
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
	double		ts;
}				t_cube;

void	init_parsing(t_cube *cube);

// 			parsing
int		parsing(char *filename, t_cube *cube);
int		parse_elements(char **file, t_cube *cube);

//			drawing
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	clear_image(t_cube *cube);
void	draw_segment(t_cube *cube, t_point a, t_point b, int color);
void	draw_square(t_cube *cube, double x, double y);
void	display_axis(t_cube *cube);
void	display_handling(t_cube *cube);
void	display_axis(t_cube *cube);

//			events
int		key_events(int keycode, t_cube *cube);

#endif
