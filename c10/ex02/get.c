/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:37:06 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/15 12:37:07 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

char	*get_stdin(int option)
{
	char	buffer[524288];
	char	*res;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (read(0, &buffer[size], 1) != 0)
		size++;
	res = ft_res(buffer, option, size);
	return (res);
}

char	*ft_res(char *membuff, int option, int size)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(option + 1);
	if (size - option > 0)
	{
		while (membuff[size - option + i])
		{
			res[i] = membuff[size - option + i];
			i++;
		}
		res[i] = 0;
	}
	else
		return (membuff);
	return (res);
}
