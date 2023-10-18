/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:20:46 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/05 17:43:13 by esoylu           ###   ########.tr       */
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
/*
#include <stdio.h>
int main(int argc, char **argv) {
    (void)argc;
	(void)argv;
	int *t = ft_range(100, 160);
	for(int i = 0; i < 60; i++) {
    	printf("%d\t", t[i]);
	}
	return 0;
}
*/
