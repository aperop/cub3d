#include "cub3d.h"

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

static void	settings_check_all(t_data *data, int *action)
{
	if (ft_strlen(data->parse_data.line) != 0 && !data->parse_data.ceiling_set)
		check_ceiling_or_floor(data, action, 'C');
	if (ft_strlen(data->parse_data.line) != 0 && !data->parse_data.floor_set)
		check_ceiling_or_floor(data, action, 'F');
	if (ft_strlen(data->parse_data.line) != 0 && !data->parse_data.text_one)
		data->parse_data.text_one = check_dir(data, action, "NO", data->texture_1);
	if (ft_strlen(data->parse_data.line) != 0 && !data->parse_data.text_two)
		data->parse_data.text_two = check_dir(data, action, "SO", data->texture_2);
	if (ft_strlen(data->parse_data.line) != 0 && \
		data->parse_data.text_three == 0)
		data->parse_data.text_three = check_dir(data, action, "WE", data->texture_3);
	if (ft_strlen(data->parse_data.line) != 0 && !data->parse_data.text_four)
		data->parse_data.text_four = check_dir(data, action, "EA", data->texture_4);
	data->map_begin++;
	if (data->parse_data.ceiling_set == 1 && data->parse_data.floor_set == 1 \
	&& data->parse_data.text_one == 1 && data->parse_data.text_two == 1 \
	&& data->parse_data.text_three == 1 && data->parse_data.text_four == 1)
		data->parse_data.all_set = 1;
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
