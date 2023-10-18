/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:54:44 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/14 14:53:49 by esoylu           ###   ########.tr       */
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

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		f;
	t_list	curr;

	while (true)
	{
		f = 0;
		curr = *begin_list;
		while (curr->next)
		{
			if (cmp(curr, curr->next))
			{
				swap_nodes(&curr->data, &curr->next->data);
				f = 0;
			}
			curr = curr->next;
		}
		if (f)
			return ;
	}
}
