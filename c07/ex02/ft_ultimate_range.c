/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:20:53 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/05 17:45:03 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ret;
	int	i;

	if (min >= max)
		return (0);
	i = 0;
	ret = (int *)malloc((max - min) * sizeof(int));
	while (i + min < max)
	{
		ret[i] = min + i;
		i++;
	}
	return (ret);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
		return (0);
	*range = ft_range(min, max);
	return (max - min);
}
