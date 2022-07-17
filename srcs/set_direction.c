/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:01:05 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/07/17 15:01:06 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_north(t_data *data, int x, int y, int *map_line)
{
	data->pos_x = x + .5;
	data->pos_y = y + .5;
	map_line[y] = 0;
	data->parse_data.direction_set = 1;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
}

void	set_south(t_data *data, int x, int y, int *map_line)
{
	data->pos_x = x + .5;
	data->pos_y = y + .5;
	map_line[y] = 0;
	data->parse_data.direction_set = 1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->dir_x = 1;
	data->plane_y = -0.66;
}

void	set_east(t_data *data, int x, int y, int *map_line)
{
	data->pos_x = x + .5;
	data->pos_y = y + .5;
	map_line[y] = 0;
	data->parse_data.direction_set = 1;
	data->dir_x = 0;
	data->dir_y = 1;
	data->plane_y = 0;
	data->plane_x = 0.66;
}

void	set_west(t_data *data, int x, int y, int *map_line)
{
	data->pos_x = x + .5;
	data->pos_y = y + .5;
	map_line[y] = 0;
	data->parse_data.direction_set = 1;
	data->dir_x = 0;
	data->dir_y = -1;
	data->plane_y = 0;
	data->plane_x = -0.66;
}

void	exit_delete_map(t_data *data, int last, int free_line)
{
	int	i;

	i = 0;
	while (i <= last)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	invalid_line_exit(data, "Error: Invalid map", free_line);
}
