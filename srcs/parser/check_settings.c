/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:37:13 by mbarra            #+#    #+#             */
/*   Updated: 2022/07/17 13:37:14 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	invalid_line_exit(t_data *data, char *msg, int free_line)
{
	if (msg != NULL)
		printf("%s\n", msg);
	if (free_line)
		free(data->parse_data.line);
	close(data->parse_data.map_fd);
	delete_and_destroy_all(data);
	exit (1);
}

static int	check_dir(t_data *data, int *action, \
					const char *dir, t_img_data *texture)
{
	char	*temp;

	temp = data->parse_data.line;
	while (*temp == ' ')
		++temp;
	if (*temp == dir[0] && ft_strlen(temp) > 2 && *(++temp) == dir[1])
	{
		if (*(++temp) != ' ')
			invalid_line_exit(data, "Error: Invalid texture.", 1);
		while (*temp == ' ')
			temp++;
		if (!fix_temp_path(temp))
			invalid_line_exit(data, "Error: Invalid texture.", 1);
		texture->img = mlx_xpm_file_to_image(data->mlx->mlx, \
	temp, &texture->width, \
	&texture->height);
		if (texture->img == NULL)
			invalid_line_exit(data, "Error: Invalid texture.", 1);
		texture->address = mlx_get_data_addr(texture->img, \
&texture->bits_per_pixel, &texture->line_length, &texture->endian);
		*action = 1;
		return (1);
	}
	return (0);
}

static void	settings_check_all(t_data *data, int *action)
{
	if (ft_strlen(data->parse_data.line) != 0 && !data->parse_data.ceiling_set)
		check_ceiling_or_floor(data, action, 'C');
	if (ft_strlen(data->parse_data.line) != 0 && !data->parse_data.floor_set)
		check_ceiling_or_floor(data, action, 'F');
	if (ft_strlen(data->parse_data.line) != 0 && !data->parse_data.text_one)
		data->parse_data.text_one = check_dir(data, action, \
											"NO", data->texture_1);
	if (ft_strlen(data->parse_data.line) != 0 && !data->parse_data.text_two)
		data->parse_data.text_two = check_dir(data, action, \
											"SO", data->texture_2);
	if (ft_strlen(data->parse_data.line) != 0 && \
		data->parse_data.text_three == 0)
		data->parse_data.text_three = check_dir(data, action, \
												"WE", data->texture_3);
	if (ft_strlen(data->parse_data.line) != 0 && !data->parse_data.text_four)
		data->parse_data.text_four = check_dir(data, action, \
											"EA", data->texture_4);
	data->map_begin++;
	if (data->parse_data.ceiling_set == 1 && data->parse_data.floor_set == 1 \
	&& data->parse_data.text_one == 1 && data->parse_data.text_two == 1 \
	&& data->parse_data.text_three == 1 && data->parse_data.text_four == 1)
		data->parse_data.all_set = 1;
}

void	malloc_fail(t_data *data, int **tempmap, int i, int flag)
{
	int	x;

	x = 0;
	if (flag == 1)
	{
		while (x < i)
		{
			free(tempmap[x]);
			x++;
		}
		free(tempmap);
	}
	exit_delete_map(data, data->map_height, 0);
}

void	settings_check(t_data *data)
{
	int	action;

	while (data->parse_data.all_set == 0 && \
get_next_line(data->parse_data.map_fd, &data->parse_data.line) != 0)
	{
		action = 0;
		settings_check_all(data, &action);
		if (action == 0 && data->parse_data.all_set == \
0 && ft_strlen(data->parse_data.line) != 0)
			invalid_line_exit(data, "Error: Extra info mapfile", 1);
		free(data->parse_data.line);
	}
	if (data->parse_data.all_set != 1)
		invalid_line_exit(data, "Error: Incomplete mapfile.", 1);
	else
		get_next_line(data->parse_data.map_fd, &data->parse_data.line);
}
