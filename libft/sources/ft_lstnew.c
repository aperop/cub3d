/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:10:32 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/09 00:23:01 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Функция ft_lstnew распределяет (с помощью malloc)
и возвращает «новый» указатель на лист.
Переменная content нового указателя инициализируется копией параметров функции.
Переменная next инициализируется значением NULL.
Если распределение завершается неудачно, функция возвращает NULL.
*/
#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		list->content = content;
		list->next = 0;
	}
	return (list);
}
