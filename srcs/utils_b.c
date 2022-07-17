/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:11:11 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/07/15 21:11:26 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	fix_temp_path(char *temp)
{
	int	i;

	i = 0;
	while (temp[i] && temp[i] != ' ')
		i++;
	if (temp[i] == ' ')
	{
		temp[i] = '\0';
		i++;
		while (temp[i] == ' ')
			i++;
	}
	if (temp[i] == '\0')
		return (1);
	else
		return (0);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	safe_exit(t_data *data)
{
	delete_and_destroy_all(data);
	exit (0);
}
