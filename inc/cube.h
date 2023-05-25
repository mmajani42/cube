/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimercie <vimercie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:29:07 by mmajani           #+#    #+#             */
/*   Updated: 2023/05/25 16:42:21 by vimercie         ###   ########lyon.fr   */
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

# define WIN_X		1920
# define WIN_Y		1080
# define Z			122
# define Q			113
# define W 			119
# define A 			97
# define S 			115
# define X 			120
# define D 			100
# define O 			111
# define P 			112
# define R 			114
# define G 			103
# define B 			98
# define ESC		65307
# define TAB		48
# define SPACE		49
// Colors
# define WHITE		0xFFFFFF
# define GREY		0x808080

// Raycast
# define PI			3.1415926535
# define FOV	    60
# define R_ONE_DEG	0.0174533
# define R_ANGLE	0.000636
# define HR			1080 / 2
# define WH			1080
# define RES		1920

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
	double	angle;
	t_point	pos;
	t_point	vec;
}			t_player;

typedef struct s_cast
{
	double	a;
	double	x;
	double	y;
	double	yo;
	double	xo;
	double	size;
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	char	type;
	double	a_tan;
}			t_cast;

typedef struct s_asset
{
	t_data	img;
	char	*path;
	int		width;
	int		height;
}				t_asset;

typedef struct s_cube
{
	t_data		img;
	void		*mlx;
	void		*mlx_win;
	int			win_x;
	int			win_y;
	double		ts;
	double		off_x;
	double		off_y;
	int			display_status;
	int			max_line_size;
	int			map_height;
	char		**file;
	char		**map;
	t_asset		no[1];
	t_asset		so[1];
	t_asset		we[1];
	t_asset		ea[1];
	double		fov_radian;
	t_cast		v_ray[RES];
	t_cast		h_ray[RES];
	t_cast		ray[RES];
	t_color		floor;
	t_color		ceiling;
	t_player	p;
}				t_cube;

void	cube_tester(t_cube *cube);

// 	parsing
int		parsing(char *filename, t_cube *cube);
int		parse_elements(t_cube *cube);
int		parse_description(t_cube *cube);

int		get_fd(char *filename);
char	**file_to_tab(char *filename);
char	*get_next_word(char *str);
char	*dup_and_fill(char *src, char c, size_t size, bool ow_last_char);

int		get_map_dimensions(char **file, t_cube *cube);

void	get_player_coordinates(t_player *p, char **map);
t_point	get_player_pos(char **map);
t_point	get_player_vec(char direction);

bool	wall_sonar(int x, int y, char **map);

bool	check_file_extension(char *filename, char *format);

// init
void	init_cube(t_cube *cube);
int		init_map(t_cube *cube);
void	init_asset(t_asset *asset, void *mlx);
void	set_tile_size(t_cube *cube);
void	set_player(t_cube *cube);

// checking
bool	is_rgb(char **tab);
bool	is_wall(char *line);
bool	is_valid_map_line(char *line);
bool	is_map_bordered(char **map);
bool	is_unique_player(char **map);

// errors
int		print_error(char *error);

// cleaning
void	free_tab(char **tab);
void	free_cube(t_cube *cube);

//	drawing
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_offset_pixel_put(t_cube *cube, int x, int y, int color);
void	draw_segment(t_cube *cube, t_point a, t_point b, int color);
void	draw_square(t_cube *cube, double x, double y);
void	draw_map(t_cube *cube);
void	draw_player(t_cube *cube);
void	draw_dot(t_cube *cube, double x, double y);
void	draw_perspective(t_cube *cube);

//	raycast
void	horizontal_ray_maths(t_cube *cube, t_cast *r, t_player *p);
void	horizontal_step(t_cube *cube, t_cast *r);
void	horizontal_raycast(t_cube *cube);

void	vertical_ray_maths(t_cube *cube, t_cast *r, t_player *p);
void	vertical_step(t_cube *cube, t_cast *r);
void	vertical_raycast(t_cube *cube);

// ray_utils
void	hit_detection(t_cube *cube, t_cast *r);
int		hit(t_cube *cube, int mx, int my);
int		p_map_pos(t_cube *cube, char c);
int		is_in_map(t_cube *cube, int x, int y);
double	reset_angle(double angle);
void	draw_closest_ray(t_cube *cube);

//	display
int		display_handling(t_cube *cube);
int		texture_display(int x, int height, t_cube *cube);
void	draw_texture_column(int x, int height, t_data texture, t_cube *cube);
void	clear_image(t_cube *cube);
void	print_tab(char **tab);

//	events
int		key_events(int keycode, t_cube *cube);
void	change_player_vector(t_cube *cube, int key);

#endif
