/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 06:48:07 by esoylu            #+#    #+#             */
/*   Updated: 2021/11/28 18:04:16 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	wrt(char a, char b);
{
	write(1, &a, 1);
	write(1, &a, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		while (j <= 99)
		{
			wrt(i / 10 + '0', i % 10 + '0');
			write(1, " ", 1);
			wrt(j / 10 + '0', j % 10 + '0');
			if (i != 98 || j != 99)
				write(1, ", ", 2);
		}
	}
}
