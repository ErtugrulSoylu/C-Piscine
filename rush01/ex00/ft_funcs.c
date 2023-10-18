/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seryilma <@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:46:45 by seryilma          #+#    #+#             */
/*   Updated: 2021/12/05 23:14:53 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

extern int	**g_table;
extern int	*g_set;
extern int	g_size;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_double_row(int position, int tower_height)
{
	int	i;
	int	max;
	int	visible_towers;

	max = 0;
	i = -1;
	visible_towers = 0;
	while (++i <= position % g_size)
	{
		if (g_table[position / g_size][i] > max)
		{
			max = g_table[position / g_size][i];
			visible_towers++;
			if (visible_towers > g_set[g_size * 2 + position / g_size])
				return (1);
		}
		if (i != position % g_size
			&& g_table[position / g_size][i] == tower_height)
			return (1);
	}
	return (0);
}

int	is_double_column(int position, int tower_height)
{
	int	i;
	int	max;
	int	visible_towers;

	max = 0;
	i = -1;
	visible_towers = 0;
	while (++i <= position / g_size)
	{
		if (g_table[i][position % g_size] > max)
		{
			max = g_table[i][position % g_size];
			visible_towers++;
			if (visible_towers > g_set[position % g_size])
				return (1);
		}
		if (i != position / g_size
			&& g_table[i][position % g_size] == tower_height)
			return (1);
	}
	return (0);
}
