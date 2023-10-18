/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:38:25 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/16 20:32:56 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
/*
char	*make_space(int file_desc)
{
	int		ret;
	char	c;
	int		len;
	char	*line;

	len = 0;
	while(1)
	{
		ret = read(file_desc, &c, 1);
		if (ret <= 0)
			break ;
	}
	line = (char *)malloc((len * 10) * sizeof(char));
	
	return (line);
}
*/
int	init(int file_desc)
{
	t_map	table;
	char	line[10000000];
	int		i;
	int		ret;

	i = 0;
	while (1)
	{
		ret = read(file_desc, line + i, 10);
		if (ret > 0)
			i += ret;
		else
		{
			line[i] = 0;
			break ;
		}
	}
	table.height = ft_atoi(line);
	if (table.height == -1 || table.height == 0)
		return (1);
	table.map = ft_split(line, table.height, '\n');
	if (table.map == 0 || init2(&table))
		return (1);
	return (0);
}

int	init2(t_map *table)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(&table->map[0][i]);
	if (len <= 3)
		return (1);
	table->fill = table->map[0][len - 1];
	table->obstacle = table->map[0][len - 2];
	table->empty = table->map[0][len - 3];
	i = len - 3;
	while (i-- > 0)
		if (table->map[0][i] < '0' || table->map[0][i] > '9')
			return (1);
	if (table->empty == table->obstacle || table->empty == table->fill
		|| table->obstacle == table->fill)
		return (1);
	table->width = ft_strlen(table->map[1]);
	i = 2;
	while (i <= table->height)
		if (table->map[i] == NULL || table->width != ft_strlen(table->map[i++]))
			return (1);
	if (init3(table))
		return (1);
	return (0);
}

int	init3(t_map *table)
{
	int	i;
	int	j;

	i = 0;
	table->dp = (int **)malloc(sizeof(int *) * table->height);
	while (i < table->height)
	{
		j = 0;
		table->dp[i] = (int *)malloc(sizeof(int) * table->width);
		while (j < table->width)
		{
			if (table->map[i + 1][j] == table->empty)
				table->dp[i][j] = 1;
			else if (table->map[i + 1][j] == table->obstacle)
				table->dp[i][j] = 0;
			else
				return (1);
			j++;
		}
		i++;
	}
	solve(table);
	return (0);
}
