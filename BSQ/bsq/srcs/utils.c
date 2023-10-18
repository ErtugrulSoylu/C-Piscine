/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:52:50 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/15 20:26:14 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

unsigned int	ft_atoi(char *str)
{
	long long	res;
	int			i;

	res = 0;
	i = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
		if (res > 2147483647)
			return (-1);
	}
	return ((int)res);
}

void	error(void)
{
	write(2, "map error\n", 10);
}

unsigned int	get_length(int file_desc)
{
	unsigned int	ret;
	unsigned int	length;
	char			c;

	length = 0;
	while (1)
	{
		ret = read(file_desc, &c, 1);
		if (ret <= 0 || c == '\n')
			break ;
		length++;
	}
	return (length);
}

char	*get_line(int length, int file_desc)
{
	char	c;
	char	*line;

	line = (char *)malloc((length + 1) * sizeof(char));
	read(file_desc, line, length);
	line[length] = '\0';
	read(file_desc, &c, 1);
	return (line);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
