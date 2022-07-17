/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:01:15 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/07/17 15:01:16 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*free_and_return_null(char *s)
{
	free(s);
	return (NULL);
}

char	*ft_strjoin_mod(char *s1, char *s2, size_t i, size_t j)
{
	char	*temp;

	if (!s1)
		return (NULL);
	if (!s2)
		return (free_and_return_null(s1));
	temp = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!temp)
		return (free_and_return_null(s1));
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		temp[i] = s2[j];
		i++;
		j++;
	}
	temp[i] = 0;
	free(s1);
	return (temp);
}
