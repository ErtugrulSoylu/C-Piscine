/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:21:51 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/02 22:38:54 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void ft_list_reverse(t_list **begin_list)
{
	t_list *cur;
	t_list *right;
	t_list *left;

	left = *begin_list;
	cur = left->next;
	left->next = 0;
	if (cur == 0)
		return ;
	right = cur->next;
	while (right != 0)
	{
		cur->next = left;
		left = cur;
		cur = right;
		right = right->next;
	}
	cur->next = left;
}
