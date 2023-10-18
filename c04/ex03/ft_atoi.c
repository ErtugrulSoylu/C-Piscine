/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:46:07 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/16 19:46:07 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	num;
	int	i;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] <= 13 && str[i] >= 9))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + ((int)(str[i] - '0'));
		i++;
	}
	return (num * sign);
}
/*
#include <stdio.h>
int    main(void)
{
	int	num;
	char	str[40] = "\n\t\v\f\r      \v\n\t  \f-0abcdefg";
	
	num = ft_atoi(str);
	printf("%d\n", num);
	return (0);
}
*/
