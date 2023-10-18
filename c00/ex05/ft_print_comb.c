/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 05:24:34 by esoylu            #+#    #+#             */
/*   Updated: 2021/11/25 06:46:59 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	wrt(char i, char j, char k)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (i != '7' || j != '8' || k != '9')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '7')
	{
		j = i +1;
		while (j <= '8')
		{
			k = j +1;
			while (k <= '9')
			{
				wrt(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
