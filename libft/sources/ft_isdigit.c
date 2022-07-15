/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:52:55 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/09 00:23:01 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Функция isdigit возвращает ненулевое значение,
если аргумент c является цифрой от 0 до 9, в противном случае возвращается 0.
*/
#include "../includes/libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
