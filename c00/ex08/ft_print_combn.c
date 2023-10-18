/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:05:59 by esoylu            #+#    #+#             */
/*   Updated: 2021/11/28 19:50:44 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	wrt(int *p, int n)
{
	int		f;
	int		i;
	char	c;

	f = 0;
	i = 0;
	while (i < n)
	{
		if (p[i] != 10 - n + i)
			f = 1;
		c = p[i++] + '0';
		write(1, &c, 1);
	}
	if (f)
		write(1, ", ", 2);
}

void	func(int *p, int n)
{
	int	i;
	int	j;

	i = n - 1;
	while (1)
	{
		if (++p[i] == 11 - n + i)
		{
			p[i--] = 0;
			if (i == -1)
				return ;
			continue ;
		}
		else
		{
			j = i;
			while (++j < n)
				p[j] = p[j - 1] + 1;
			wrt(p, n);
			i = n - 1;
		}
	}
}

void	ft(int n)
{
	int	p[10];
	int	i;

	i = -1;
	while (++i < n)
		p[i] = i;
	wrt(p, n);
	func(p, n);
}
