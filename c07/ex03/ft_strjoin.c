/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:21:30 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/08 01:24:21 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	all_length(int size, char **strs, int sep_len)
{
	int	length;

	length = 0;
	while (size-- > 0)
	{
		length += len(strs[size]);
		length += sep_len;
	}
	length -= sep_len;
	return (length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		c;
	int		i;
	int		j;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	c = 0;
	i = -1;
	ret = (char *)malloc(sizeof(char) * (all_length(size, strs, len(sep)) + 1));
	while (++i < size - 1)
	{
		j = 0;
		while (strs[i][j] != '\0')
			ret[c++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0')
			ret[c++] = sep[j++];
	}
	j = 0;
	while (strs[i][j] != '\0')
		ret[c++] = strs[i][j++];
	ret[c] = '\0';
	return (ret);
}
/*
#include <stdio.h>
int main(int argc, char **argv) {
	printf("%s", ft_strjoin(argc-2, &argv[1], argv[argc-1]));
	return 0;
}
*/
