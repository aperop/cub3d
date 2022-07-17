/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:11:05 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/07/15 21:11:26 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	parse_data_init(t_data *data)
{
	data->parse_data.main_img_set = 0;
	data->parse_data.text_one = 0;
	data->parse_data.text_two = 0;
	data->parse_data.text_three = 0;
	data->parse_data.text_four = 0;
	data->parse_data.ceiling_set = 0;
	data->parse_data.floor_set = 0;
	data->parse_data.all_set = 0;
	data->parse_data.direction_set = 0;
	data->map_begin = 0;
}

int	structs_init(t_data *data)
{
	parse_data_init(data);
	data->mlx = malloc(sizeof(t_mlx_vars));
	if (data->mlx == NULL)
		return (delete_structs(data, 0));
	data->img = malloc(sizeof(t_img_data));
	if (data->img == NULL)
		return (delete_structs(data, 1));
	data->texture_1 = malloc(sizeof(t_img_data));
	if (data->texture_1 == NULL)
		return (delete_structs(data, 2));
	data->texture_2 = malloc(sizeof(t_img_data));
	if (data->texture_2 == NULL)
		return (delete_structs(data, 3));
	data->texture_3 = malloc(sizeof(t_img_data));
	if (data->texture_3 == NULL)
		return (delete_structs(data, 4));
	data->texture_4 = malloc(sizeof(t_img_data));
	if (data->texture_4 == NULL)
		return (delete_structs(data, 5));
	return (1);
}
