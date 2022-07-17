/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:11:02 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/07/15 21:11:26 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	rotate(t_data *data, double rotate_speed)
{
    double	old_dir_x;
    double	old_plane_x;

    old_dir_x = data->dir_x;
    data->dir_x = data->dir_x * cos(-rotate_speed) - \
data->dir_y * sin(-rotate_speed);
    data->dir_y = old_dir_x * sin(-rotate_speed) + \
data->dir_y * cos(-rotate_speed);
    old_plane_x = data->plane_x;
    data->plane_x = data->plane_x * cos(-rotate_speed) - \
data->plane_y * sin(-rotate_speed);
    data->plane_y = old_plane_x * sin(-rotate_speed) + \
data->plane_y * cos(-rotate_speed);
    render_next_frame(data);
}

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(ROTATE_SPEED) - \
data->dir_y * sin(ROTATE_SPEED);
	data->dir_y = old_dir_x * sin(ROTATE_SPEED) + \
data->dir_y * cos(ROTATE_SPEED);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(ROTATE_SPEED) - \
data->plane_y * sin(ROTATE_SPEED);
	data->plane_y = old_plane_x * sin(ROTATE_SPEED) + \
data->plane_y * cos(ROTATE_SPEED);
	render_next_frame(data);
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-ROTATE_SPEED) - \
data->dir_y * sin(-ROTATE_SPEED);
	data->dir_y = old_dir_x * sin(-ROTATE_SPEED) + \
data->dir_y * cos(-ROTATE_SPEED);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(-ROTATE_SPEED) - \
data->plane_y * sin(-ROTATE_SPEED);
	data->plane_y = old_plane_x * sin(-ROTATE_SPEED) + \
data->plane_y * cos(-ROTATE_SPEED);
	render_next_frame(data);
}

int	keypressed(int keycode, t_data	*data)
{
	if (keycode == UP_KEY)
		up_pressed(data);
	if (keycode == DOWN_KEY)
		down_pressed(data);
	if (keycode == LEFT_KEY)
		left_pressed(data);
	if (keycode == RIGHT_KEY)
		right_pressed(data);
	if (keycode == LEFT_ROTATE)
		rotate_left(data);
	if (keycode == RIGHT_ROTATE)
		rotate_right(data);
	if (keycode == ESC_KEY)
		safe_exit(data);
	if (data->dir_x == 0 || data->dir_x == 1 || data->dir_x == -1 || \
		data->dir_y == 0 || data->dir_y == 1 || data->dir_y == -1)
		rotate(data, 0.001);
	return (0);
}
