/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:27:00 by esoylu            #+#    #+#             */
/*   Updated: 2021/11/25 11:30:28 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_sort_int_tab(int *tab, int size)
{
	int	f;
	int	n;
	int	tmp1;
	int	tmp2;

	f = 1;
	while (f)
	{
		f = 0;
		n = size;
		while (--n > 0)
		{
			tmp1 = *tab;
			tab++;
			tmp2 = *tab;
			if (tmp1 > tmp2)
			{
				f = 1;
				tab--;
				*(tab++) = tmp2;
				*tab = tmp1;
			}
		}
		tab -= size - 1;
	}
}
