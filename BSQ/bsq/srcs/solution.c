/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:38:33 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/15 20:24:40 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	solve(t_map *table)
{
	int	i;
	int	j;
	int	maxi;
	int	maxj;
	int	max;

	i = -1;
	max = 0;
	while (++i < table->height)
	{
		j = -1;
		while (++j < table->width)
		{
			if (i > 0 && j > 0 && table->dp[i][j] == 1)
				table->dp[i][j] = ft_min(ft_min(table->dp[i - 1][j],
							table->dp[i][j - 1]), table->dp[i - 1][j - 1]) + 1;
			if (table->dp[i][j] > max)
			{
				maxi = i;
				maxj = j;
				max = table->dp[i][j];
			}
		}
	}
	display(table, maxi, maxj, 0);
}

void	display(t_map *table, int maxi, int maxj, int i)
{
	int	j;

	i = maxi - table->dp[maxi][maxj];
	while (++i <= maxi)
	{
		j = maxj - table->dp[maxi][maxj];
		while (++j <= maxj)
			table->dp[i][j] = -1;
	}
	i = -1;
	while (++i < table->height)
	{
		j = -1;
		while (++j < table->width)
		{
			if (table->dp[i][j] == -1)
				write(1, &table->fill, 1);
			else if (table->dp[i][j] == 0)
				write(1, &table->obstacle, 1);
			else
				write(1, &table->empty, 1);
		}
		write(1, "\n", 1);
	}
}
