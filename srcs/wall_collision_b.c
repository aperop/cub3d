/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:11:16 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/07/15 21:11:26 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_next_pos_left_x(t_data *data)
{
	int		temp_int;
	double	temp_float;
	double	value;
	int		pos_next;
	double	look_dir_x;

	look_dir_x = data->dir_y;
	value = data->pos_x - look_dir_x * MOVE_SPEED;
	temp_int = (int)value;
	temp_float = value - (double)temp_int;
	if (look_dir_x < 0)
		pos_next = (int)data->pos_x + 1;
	else
		pos_next = (int)data->pos_x - 1;
	if ((int)data->pos_x == (int)value && \
data->map[pos_next][(int)data->pos_y] == 1)
	{
		if (pos_next > (int)data->pos_x && temp_float > 0.90)
			return (0);
		else if (pos_next < (int)data->pos_x && temp_float < 0.10)
			return (0);
	}
	return (1);
}

int	check_next_pos_left_y(t_data *data)
{
	int		temp_int;
	double	temp_float;
	double	value;
	int		pos_next;
	double	look_dir_y;

	look_dir_y = data->dir_x;
	value = data->pos_y + look_dir_y * MOVE_SPEED;
	temp_int = (int)value;
	temp_float = value - (double)temp_int;
	if (look_dir_y < 0)
		pos_next = (int)data->pos_y - 1;
	else
		pos_next = (int)data->pos_y + 1;
	if ((int)data->pos_y == (int)value && \
data->map[(int)data->pos_x][pos_next] == 1)
	{
		if (pos_next > (int)data->pos_y && temp_float > 0.90)
			return (0);
		else if (pos_next < (int)data->pos_y && temp_float < 0.10)
			return (0);
	}
	return (1);
}

int	check_next_pos_right_x(t_data *data)
{
	int		temp_int;
	double	temp_float;
	double	value;
	int		pos_next;
	double	look_dir_x;

	look_dir_x = data->dir_y;
	value = data->pos_x + look_dir_x * MOVE_SPEED;
	temp_int = (int)value;
	temp_float = value - (double)temp_int;
	if (look_dir_x < 0)
		pos_next = (int)data->pos_x - 1;
	else
		pos_next = (int)data->pos_x + 1;
	if ((int)data->pos_x == (int)value && \
data->map[pos_next][(int)data->pos_y] == 1)
	{
		if (pos_next > (int)data->pos_x && temp_float > 0.90)
			return (0);
		else if (pos_next < (int)data->pos_x && temp_float < 0.10)
			return (0);
	}
	return (1);
}

int	check_next_pos_right_y(t_data *data)
{
	int		temp_int;
	double	temp_float;
	double	value;
	int		pos_next;
	double	look_dir_y;

	look_dir_y = data->dir_x;
	value = data->pos_y - look_dir_y * MOVE_SPEED;
	temp_int = (int)value;
	temp_float = value - (double)temp_int;
	if (look_dir_y < 0)
		pos_next = (int)data->pos_y + 1;
	else
		pos_next = (int)data->pos_y - 1;
	if ((int)data->pos_y == (int)value && \
data->map[(int)data->pos_x][pos_next] == 1)
	{
		if (pos_next > (int)data->pos_y && temp_float > 0.90)
			return (0);
		else if (pos_next < (int)data->pos_y && temp_float < 0.10)
			return (0);
	}
	return (1);
}
