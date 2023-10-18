/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:59:29 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/05 23:36:37 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_funcs.h"

int	**g_table;
int	*g_set;
int	g_size;

int	check(char **av)
{
	int	i;

	i = -1;
	if ((g_size + 1) % 8 != 0)
		return (1);
	g_size = (g_size + 1) / 8;
	if (g_size < 1 || g_size > 9)
		return (1);
	while (av[1][++i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (av[1][i] < '1' || av[1][i] > g_size + '0')
				return (1);
		}
		else if (av[1][i] != ' ')
			return (1);
	}
	return (0);
}

int	solve(int position)
{
	int	tower_height;

	if (position == g_size * g_size)
		return (1);
	tower_height = 0;
	while (++tower_height <= g_size)
	{
		g_table[position / g_size][position % g_size] = tower_height;
		if (!is_double_row(position, tower_height)
			&& !is_double_column(position, tower_height)
			&& check_case(position) == 0 && solve(position + 1) == 1)
			return (1);
		g_table[position / g_size][position % g_size] = 0;
	}
	return (0);
}

void	display_solution(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_size)
	{
		j = -1;
		while (++j < g_size)
		{
			ft_putchar(g_table[i][j] + '0');
			if (j != g_size - 1)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

void	free_func(void)
{
	int	i;

	i = 1;
	while (++i < g_size)
		free(g_table[i]);
	free (g_set);
	free (g_table);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (ft_putstr("Error\n"));
	g_size = ft_strlen(av[1]);
	if (check(av) == 1)
		return (ft_putstr("Error\n"));
	g_table = malloc (sizeof(int *) * g_size);
	i = -1;
	while (++i < g_size)
		g_table[i] = malloc(sizeof(int) * g_size);
	g_set = malloc (sizeof(int) * 4 * g_size);
	i = -1;
	while (av[1][++i] != '\0')
		if (av[1][i] != ' ')
			g_set[i / 2] = av[1][i] - '0';
	if (solve(0) == 1)
		display_solution();
	else
		(void)ft_putstr("Error\n");
	free_func();
	return (0);
}
