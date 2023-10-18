/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:08:05 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/02 14:12:35 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = -1;
	j = size;
	while (++i < --j)
	{
		tab[i] += tab[j];
		tab[j] = tab[i] - tab[j];
		tab[i] -= tab[j];
	}
}

#include <stdio.h>
int main () {
	int tab[] = {1,2,3,4,5,6,7,8};
	int size = 8;
	ft_rev_int_tab(tab, size);
	for(int i = 0; i < size; i++) {
		printf("%d ", tab[i]);
	}
	return 0;
}
