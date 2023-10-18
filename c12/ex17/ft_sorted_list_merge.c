/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:54:44 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/14 15:45:47 by esoylu           ###   ########.tr       */
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

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*curr;
	t_list	*node;

	if (*begin_list == NULL)
		*begin_list = ft_create_elem(data);
	curr = *begin_list;
	if (cmp(data, curr))
	{
		node = ft_create_elem(data);
		node->next = curr;
		*begin_list = curr;
		return ;
	}
	while (curr->next)
	{
		if (cmp(curr->data, data))
		{
			node = curr->next;
			curr->next = ft_create_elem(data);
			curr->next->next = node;
			return ;
		}
	}
	curr->next = ft_create_elem(data);
}

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	if (!begin_list2)
		return ;
	while (begin_list2)
	{
		ft_sorted_list_insert(begin_list1, begin_list2->data, cmp);
		begin_list2 = begin_list2->next;
	}
}
