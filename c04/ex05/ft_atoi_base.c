/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:46:21 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/16 19:46:22 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	find_sign(char *str, int *i)
{
	int	count;

	count = 0;
	while ((str[*i] == '-') || (str[*i] == '+'))
	{
		if (str[*i] == '-')
			count++;
		*i += 1;
	}
	if (count % 2 == 1)
		return (-1);
	return (1);
}

int	check(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i] != '\0')
	{
		if ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
			return (0);
		if (str[i] == '-' || str[i] == '+')
			return (0);
		j = 0;
		while (str[i + j++] != '\0')
			if (str[i] == str[i + j])
				return (0);
	}
	if (i == 0 || i == 1)
		return (0);
	else
		return (1);
}

int	find_index(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == c)
			return (i);
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	num;
	int	i;
	int	base_l;

	if (check(base) == 0)
		return (0);
	i = -1;
	num = 0;
	while (base[++i] != '\0')
		i++;
	base_l = i;
	i = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	sign = find_sign(str, &i);
	while (find_index(base, str[i]) != -1)
	{
		num = (num * base_l) + find_index(base, str[i]);
		i++;
	}
	return (num * sign);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[30] = "\n \t \v \f \r  ---+++-11111";
	char	str2[30] = "01\r";
		printf("%d\n", ft_atoi_base(str, str2));
	return (0);
}
*/
