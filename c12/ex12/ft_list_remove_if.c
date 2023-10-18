/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:09:14 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/03 00:50:30 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*to_link;
	t_list	*cur;
	t_list	*del;

	to_link = 0;
	cur = *begin_list;
	while (cur != 0)
	{
		while (cur != 0 && (*cmp)(cur->data, data_ref) == 0)
		{
			del = cur;
			cur = cur->next;
			(*free_fct)(del);
		}
		if (to_link != 0 && cur != 0)
			to_link->next = cur;
		while (cur != 0 && (*cmp)(cur->data, data_ref) != 0)
		{
			to_link = cur;
			cur = cur->next;
		}
	}
}
