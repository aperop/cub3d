/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:37:08 by mbarra            #+#    #+#             */
/*   Updated: 2022/07/17 13:41:15 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_tempmap(t_data *data, int **tempmap)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		free(tempmap[i]);
		i++;
	}
	free(tempmap);
}

void	free_temp_and_exit(t_data *data, int **tempmap)
{
	free_tempmap(data, tempmap);
	exit_delete_map(data, data->map_height, 0);
}

static void	parse_map_line(t_data *data, int *map_line, int x, int i)
{
	if (data->parse_data.direction_set == 0 && data->parse_data.line[i] == 'N')
		set_north(data, x, i, map_line);
	else if (data->parse_data.direction_set == 0 && \
data->parse_data.line[i] == 'S')
		set_south(data, x, i, map_line);
	else if (data->parse_data.direction_set == 0 && \
data->parse_data.line[i] == 'W')
		set_west(data, x, i, map_line);
	else if (data->parse_data.direction_set == 0 && \
data->parse_data.line[i] == 'E')
		set_east(data, x, i, map_line);
	else if (data->parse_data.line[i] == '0' || \
data->parse_data.line[i] == ' ')
		map_line[i] = 0;
	else if (data->parse_data.line[i] == '1')
		map_line[i] = 1;
	else
		exit_delete_map(data, x, 1);
}

static void	copy_map_line(t_data *data, int *map_line, int x)
{
	int	i;

	i = 0;
	while (data->parse_data.line[i] != '\0')
		parse_map_line(data, map_line, x, i++);
	while (i < data->map_width)
		map_line[i++] = 0;
}

void	get_map(char **argv, t_data *data)
{
	int	i;

	data->map = malloc(sizeof(int *) * (data->map_height + 1));
	data->map[data->map_height] = NULL;
	check_map_filepath(argv, data);
	i = -1;
	while (++i < data->map_begin)
	{
		get_next_line(data->parse_data.map_fd, &data->parse_data.line);
		if (i + 1 < data->map_begin)
			free(data->parse_data.line);
	}
	data->map[0] = malloc(sizeof(int) * data->map_width);
	copy_map_line(data, data->map[0], 0);
	free(data->parse_data.line);
	i = 0;
	while (++i < data->map_height)
	{
		get_next_line(data->parse_data.map_fd, &data->parse_data.line);
		data->map[i] = malloc(sizeof(int) * data->map_width);
		copy_map_line(data, data->map[i], i);
		free(data->parse_data.line);
	}
	if (data->parse_data.direction_set == 0)
		exit_delete_map(data, i, 0);
}
