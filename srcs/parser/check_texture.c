#include "cub3d.h"

int	check_dir(t_data *data, int *action, const char *dir, t_img_data *texture)
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
