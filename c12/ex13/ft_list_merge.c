/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:51:09 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/03 00:54:11 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	while ((*begin_list1)->next != 0)
		*begin_list1 = (*begin_list1)->next;
   (*begin_list1)->next = begin_list2;	
}
