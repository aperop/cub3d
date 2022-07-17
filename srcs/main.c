/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:10:33 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/07/15 21:11:26 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	game_loop(t_data *data)
{
	(void)data;
	return (0);
}

static	void	arg_check(int argc, char **argv)
{
	size_t	arg_len;
	char	*mapfile;

	if (argc != 2)
	{
		printf("Error!\n Wrong number of arguments.\n");
		exit(1);
	}
	arg_len = ft_strlen(argv[1]);
	if (arg_len < 5)
	{
		printf("Error!\n Wrong map file format.\n");
		exit(1);
	}
	mapfile = ft_substr(argv[1], arg_len - 4, 4);
	if (ft_strncmp(mapfile, ".cub", 4) != 0)
	{
		printf("Error!\n Wrong map file format.\n");
		free(mapfile);
		exit(1);
	}
	free(mapfile);
}

int	close_button(t_data *data)
{
	safe_exit(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	arg_check(argc, argv);
	data = malloc(sizeof(t_data));
	if (data == NULL || !structs_init(data))
		return (1);
	data->mlx->mlx = mlx_init();
	data->mlx->mlx_window = mlx_new_window(data->mlx->mlx, WINWIDTH, \
WINHEIGHT, "cub3d");
	data->img->img = mlx_new_image(data->mlx->mlx, WINWIDTH, WINHEIGHT);
	data->img->address = mlx_get_data_addr(data->img->img, \
&data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	data->parse_data.main_img_set = 1;
	map_check_init(argv, data);
	rotate(data, 0.001);
	mlx_hook(data->mlx->mlx_window, 2, 1L << 0, keypressed, data);
	mlx_hook(data->mlx->mlx_window, 17, 0L, close_button, data);
	render_next_frame(data);
	mlx_loop_hook(data->mlx->mlx, game_loop, data);
	mlx_loop(data->mlx->mlx);
	return (0);
}
