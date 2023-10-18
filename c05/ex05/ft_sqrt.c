/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:44:03 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/16 19:44:05 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	x;

	if (nb < 0)
		return (0);
	x = 0;
	while ((x * x <= nb))
	{
		if (x == 46341)
			break ;
		if (nb == (x * x))
			return (x);
		x++;
	}
	return (0);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%d\n", ft_sqrt(atoi(av[1])));
	return (0);
}
*/
