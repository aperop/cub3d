/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:02:42 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/07/17 15:02:43 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define WINWIDTH 1024
# define WINHEIGHT 768
# define ROTATE_SPEED 0.05
# define MOVE_SPEED 1
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct s_img_data {
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img_data;

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*mlx_window;
}				t_mlx_vars;

typedef struct s_parse_data
{
	int		map_fd;
	int		direction_set;
	int		main_img_set;
	int		text_one;
	int		text_two;
	int		text_three;
	int		text_four;
	int		ceiling_set;
	int		floor_set;
	int		all_set;
	char	*line;
}				t_parse_data;

typedef struct s_data
{
	t_mlx_vars		*mlx;
	t_img_data		*img;
	t_img_data		*texture_1;
	t_img_data		*texture_2;
	t_img_data		*texture_3;
	t_img_data		*texture_4;
	t_img_data		*loaded_texture;
	t_parse_data	parse_data;
	int				**map;
	int				map_begin;
	int				map_height;
	int				map_width;
	int				ceiling_color;
	int				floor_color;
	int				vert_line_color;
	char			**rgb;
	int				r;
	int				g;
	int				b;
	char			*temp;
	char			*error;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				x;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	int				y;
	int				d;
	int				i;
	int				text_number;
}				t_data;

void	map_check_init(char **argv, t_data *data);
void	settings_check(t_data *data);
void	get_map(char **argv, t_data *data);
void	invalid_line_exit(t_data *data, char *msg, int free_line);
int		structs_init(t_data *data);
int		delete_structs(t_data *data, int count);
void	delete_and_destroy_all(t_data *data);
void	check_map_filepath(char **argv, t_data *data);
void	exit_delete_map(t_data *data, int last, int free_line);
void	free_temp_and_exit(t_data *data, int **tempmap);
void	set_north(t_data *data, int x, int y, int *map_line);
void	set_south(t_data *data, int x, int y, int *map_line);
void	set_east(t_data *data, int x, int y, int *map_line);
void	set_west(t_data *data, int x, int y, int *map_line);
int		fix_temp_path(char *temp);
void	safe_exit(t_data *data);
void	malloc_fail(t_data *data, int **tempmap, int i, int flag);
void	free_tempmap(t_data *data, int **tempmap);
void	check_map(t_data *data);

void	free_split(char **words);
int		ft_str_isnum(char *str);
int		create_trgb(int t, int r, int g, int b);

int		keypressed(int keycode, t_data	*data);
void	rotate(t_data *data, double rotate_speed);
void	down_pressed(t_data *data);
void	up_pressed(t_data *data);
void	left_pressed(t_data *data);
void	right_pressed(t_data *data);

int		check_next_pos_down_x(t_data *data);
int		check_next_pos_down_y(t_data *data);
int		check_next_pos_up_x(t_data *data);
int		check_next_pos_up_y(t_data *data);
int		check_next_pos_left_x(t_data *data);
int		check_next_pos_left_y(t_data *data);
int		check_next_pos_right_x(t_data *data);
int		check_next_pos_right_y(t_data *data);

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void	draw_vertical_line(t_data *data, int x, int begin, int end);
int		render_next_frame(t_data *data);
void	texture_setter(t_data *data);
void	vertical_line_calc(t_data *data);
void	draw_window_line(t_data *data);

void	check_ceiling_or_floor(t_data *data, int *action, char cf);

# ifndef KEYCODES_OSX_H
#  define KEYCODES_OSX_H

#  define UP_KEY 13
#  define LEFT_KEY 0
#  define DOWN_KEY 1
#  define RIGHT_KEY 2

#  define LEFT_ROTATE 123
#  define RIGHT_ROTATE 124

#  define ESC_KEY 53

# endif //KEYCODES_OSX_H

#endif //CUB3D_H
