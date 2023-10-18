/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 04:30:49 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/15 20:07:53 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strncpy(char *src, unsigned int n)
{
	char			*dest;
	unsigned int	i;

	if (n == 0)
		return (0);
	dest = (char *)malloc((n + 1) * sizeof(char));
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, int len, char set)
{
	char	**ret;
	int		ret_index;
	int		i;

	i = 0;
	ret = malloc((len + 1) * sizeof(char *));
	ret_index = 0;
	while (*str != '\0' && str[i] == set)
		str++;
	while (*str != '\0')
	{
		i = 0;
		while (str[i] != '\0' && str[i] != set)
			i++;
		ret[ret_index] = ft_strncpy(str, i);
		while (str[i] != '\0' && str[i] == set)
			i++;
		if (str[i] != '\0')
			str = &str[i];
		else
			break ;
		ret_index++;
	}
	return (ret);
}

int	ft_min(int i1, int i2)
{
	if (i1 < i2)
		return (i1);
	return (i2);
}
