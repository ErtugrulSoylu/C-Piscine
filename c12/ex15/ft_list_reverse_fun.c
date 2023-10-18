/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:54:44 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/14 15:19:57 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void swap_nodes(void **data1, void **data2)
{
	void *data;

	data = *data1;
	*data1 = *data2;
	*data2 = data;
}

void ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		j;
	t_list	arr[1000];

	j = 0;
	i = -1;
	while (*begin_list)
	{
		i++;
		arr[i] = *begin_list;
		*begin_list = (*begin_list)->next;
	}
	while (j < i)
	{
		swap_nodes(&arr[i]->node, &arr[j]->node);
		j++;
		i--;
	}
}
