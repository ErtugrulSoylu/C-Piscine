/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:11:02 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/07 14:39:47 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

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

int	ft_strhas(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	**ft_split(char *str, char *set)
{
	char	**ret;
	int		ret_index;
	int		i;

	ret = malloc(1000 * sizeof(char *));
	ret_index = 0;
	while (*str != '\0' && ft_strhas(*str, set))
		str++;
	while (*str != '\0')
	{
		i = 0;
		while (str[i] != '\0' && !ft_strhas(str[i], set))
			i++;
		ret[ret_index] = ft_strncpy(str, i);
		while (str[i] != '\0' && ft_strhas(str[i], set))
			i++;
		if (str[i] != '\0')
			str = &str[i];
		else
			break ;
		ret_index++;
	}
	return (ret);
}
/*
int main(int argc, char **argv)
{
	int i = 0;
	char **c = ft_split(argv[1], argv[2]);
	while(c[i] != 0) {
		printf("%s\n", c[i]);
		i++;
	}
	return 0;
}
*/
