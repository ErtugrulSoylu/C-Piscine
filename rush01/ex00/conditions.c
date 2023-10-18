/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:08:39 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/05 23:15:19 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

extern int	**g_table;
extern int	*g_set;
extern int	g_size;

int	check_coldown(int position)
{
	int	i;
	int	max;
	int	visible_towers;

	i = g_size;
	max = 0;
	visible_towers = 0;
	if (position / g_size == g_size - 1)
	{
		while (--i >= 0)
		{
			if (g_table[i][position % g_size] > max)
			{
				max = g_table[i][position % g_size];
				visible_towers++;
			}
		}
		if (g_set[g_size + position % g_size] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_rowright(int position)
{
	int	i;
	int	max;
	int	visible_towers;

	i = g_size;
	max = 0;
	visible_towers = 0;
	if (position % g_size == g_size - 1)
	{
		while (--i >= 0)
		{
			if (g_table[position / g_size][i] > max)
			{
				max = g_table[position / g_size][i];
				visible_towers++;
			}
		}
		if (g_set[g_size * 3 + position / g_size] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_case(int position)
{
	if (check_rowright(position) == 1)
		return (1);
	if (check_coldown(position) == 1)
		return (1);
	return (0);
}
