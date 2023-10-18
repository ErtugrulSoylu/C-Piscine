/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:36:29 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/15 12:37:39 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str, int j)
{
	int	i;
	int	res;

	res = 0;
	i = j;
	if (!ft_is_numeric(str[i]))
		return (-1);
	while (ft_is_numeric(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}
