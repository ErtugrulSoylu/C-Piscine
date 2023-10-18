/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:44:28 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/16 19:44:30 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display(int *tab)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			if (tab[10 * i + j] == 1)
			{
				temp = j + 48;
				write(1, &temp, 1);
				break ;
			}
		}
	}
}

int	check(int *tab, int i, int j)
{
	int	ind_i;
	int	ind_j;
	int	ind_k;

	ind_i = -1;
	while (++ind_i < i)
		if (tab[10 * ind_i + j] == 1)
			return (0);
	ind_i = i - 1;
	ind_j = j + 1;
	ind_k = j - 1;
	while (1)
	{
		if ((ind_i == -1) || ((ind_j == 10) && (ind_k == -1)))
			break ;
		if (((ind_j <= 9) && (tab[10 * ind_i + ind_j] == 1)) || ((ind_k >= 0)
				&& (tab[10 * ind_i + ind_k] == 1)))
			return (0);
		ind_i--;
		if (ind_j <= 9)
			ind_j++;
		if (ind_k >= 0)
			ind_k--;
	}
	return (1);
}

int	solve(int *tab, int i, int *count)
{
	int	j;

	j = 0;
	while (j < 10)
	{
		if (check(tab, i, j))
		{
			tab[10 * i + j] = 1;
			if (i == 9)
			{
				display(tab);
				write(1, "\n", 1);
				*count += 1;
				tab[10 * i + j] = 0;
			}
			else if (!solve(tab, i + 1, count))
				tab[10 * i + j] = 0;
		}
		j++;
	}
	if (i == 0)
		return (*count);
	else
		return (0);
}

int	ft_ten_queens_puzzle(void)
{
	int	tab[100];
	int	count;
	int	i;

	i = -1;
	while (++i < 100)
		tab[i] = 0;
	count = 0;
	i = 0;
	return (solve(tab, i, &count));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_ten_queens_puzzle());
	return (0);
}
*/
