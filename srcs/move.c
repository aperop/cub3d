/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:10:46 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/07/15 21:11:26 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	left_pressed(t_data *data)
{
	double	look_dir_x;
	double	look_dir_y;

	look_dir_x = data->dir_y;
	look_dir_y = data->dir_x;
	if (data->map[(int)(data->pos_x - look_dir_x * \
	MOVE_SPEED)][(int)(data->pos_y)] == 0 && check_next_pos_left_x(data) == 1)
		data->pos_x -= look_dir_x * MOVE_SPEED;
	if (data->map[(int)(data->pos_x)][(int)(data->pos_y + look_dir_y * \
	MOVE_SPEED)] == 0 && check_next_pos_left_y(data) == 1)
		data->pos_y += look_dir_y * MOVE_SPEED;
	render_next_frame(data);
}

void	right_pressed(t_data *data)
{
	double	look_dir_x;
	double	look_dir_y;

	look_dir_x = data->dir_y;
	look_dir_y = data->dir_x;
	if (data->map[(int)(data->pos_x + look_dir_x * \
	MOVE_SPEED)][(int)(data->pos_y)] == 0 && check_next_pos_right_x(data) == 1)
		data->pos_x += look_dir_x * MOVE_SPEED;
	if (data->map[(int)(data->pos_x)][(int)(data->pos_y - \
	look_dir_y * MOVE_SPEED)] == 0 && check_next_pos_right_y(data) == 1)
		data->pos_y -= look_dir_y * MOVE_SPEED;
	render_next_frame(data);
}

void	down_pressed(t_data *data)
{
	if (data->map[(int)(data->pos_x - data->dir_x * \
	MOVE_SPEED)][(int)(data->pos_y)] == 0 && check_next_pos_down_x(data) == 1)
		data->pos_x = data->pos_x - data->dir_x * MOVE_SPEED;
	if (data->map[(int)(data->pos_x)][(int)(data->pos_y - \
	data->dir_y * MOVE_SPEED)] == 0 && check_next_pos_down_y(data) == 1)
		data->pos_y = data->pos_y - data->dir_y * MOVE_SPEED;
	render_next_frame(data);
}

void	up_pressed(t_data *data)
{
	if (data->map[(int)(data->pos_x + data->dir_x * \
	MOVE_SPEED)][(int)(data->pos_y)] == 0 && check_next_pos_up_x(data) == 1)
		data->pos_x = data->pos_x + data->dir_x * MOVE_SPEED;
	if (data->map[(int)(data->pos_x)][(int)(data->pos_y + \
	data->dir_y * MOVE_SPEED)] == 0 && check_next_pos_up_y(data) == 1)
		data->pos_y = data->pos_y + data->dir_y * MOVE_SPEED;
	render_next_frame(data);
}
