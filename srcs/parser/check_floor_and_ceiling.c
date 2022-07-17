#include "cub3d.h"

static int	valid_last_rgb(char *blue)
{
	int	i;

	i = 0;
	if (!ft_isdigit(blue[i]))
		return (0);
	while (ft_isdigit(blue[i]))
		i++;
	while (blue[i] == ' ')
		i++;
	if (blue[i] != '\0')
		return (0);
	else
		return (1);
}

static int	rgb_to_hex(t_data *data, const int *current)
{
	int	i;

	i = *current;
	if (ft_str_isnum(data->rgb[i]) == 0 && i != 2)
		return (0);
	if (i == 2 && !valid_last_rgb(data->rgb[i]))
		return (0);
	if (i == 0)
		data->r = ft_atoi(data->rgb[i]);
	else if (i == 1)
		data->g = ft_atoi(data->rgb[i]);
	else if (i == 2)
		data->b = ft_atoi(data->rgb[i]);
	if (ft_atoi(data->rgb[i]) < 0 || ft_atoi(data->rgb[i]) > 255)
		return (0);
	return (1);
}

static int	split_rgb(char *decimals, t_data *data)
{
	int		i;

	i = 0;
	data->rgb = ft_split(decimals, ',');
	while (data->rgb[i])
	{
		if (!rgb_to_hex(data, &i))
		{
			free_split(data->rgb);
			return (-1);
		}
		i++;
	}
	free_split(data->rgb);
	if (i != 3)
		return (-1);
	else
		return (create_trgb(0, data->r, data->g, data->b));
}

static void	floor_ceiling_rgb(t_data *data, int *action, char c)
{
	if (c == 'C')
	{
		data->ceiling_color = split_rgb(data->temp, data);
		data->parse_data.ceiling_set = 1;
		*action = 1;
	}
	else if (c == 'F')
	{
		data->floor_color = split_rgb(data->temp, data);
		data->parse_data.floor_set = 1;
		*action = 1;
	}
}

void	check_ceiling_or_floor(t_data *data, int *action, const char cf)
{
	data->error = "Error: Invalid RGB line.";
	data->temp = data->parse_data.line;
	while (*data->temp == ' ')
		data->temp++;
	if (*data->temp == cf)
	{
		data->temp++;
		if (*data->temp != ' ')
			invalid_line_exit(data, data->error, 1);
		while (*data->temp == ' ')
			data->temp++;
		if (ft_isdigit(*data->temp))
		{
			if (split_rgb(data->temp, data) > 0)
			{
				floor_ceiling_rgb(data, action, cf);
				return ;
			}
			else
				invalid_line_exit(data, data->error, 1);
		}
		else
			invalid_line_exit(data, data->error, 1);
	}
}
