/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:50:46 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/08 10:57:24 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#define NO_MATCH -1

int		ft_str_length(char *str);
int		compute_number_length(unsigned int number, int radix, bool negative);
bool	is_space(char c);
bool	is_base_valid(char *str);

int	resolve_base(char *base, char match)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (base[index] == match)
			return (index);
		index++;
	}
	return (NO_MATCH);
}

char	*ft_buffer_base(char *base, unsigned int number, bool negative)
{
	int		index;
	int		radix;
	int		length;
	char	*string;

	radix = ft_str_length(base);
	length = compute_number_length(number, radix, negative);
	string = (char *)malloc((length + 1) * sizeof(char));
	if (string == 0)
		return (0);
	if (negative)
		string[0] = '-';
	index = 0;
	if (negative)
		index = 1;
	while (index < length)
	{
		string[length - (!negative) - index++] = base[number % radix];
		number /= radix;
	}
	string[length] = '\0';
	return (string);
}

bool	neg(int num)
{
	if (num <= 0)
		return (true);
	return (false);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				radix;
	int				minus;
	unsigned int	result;

	if (!is_base_valid(base_from) || !is_base_valid(base_to))
		return (NULL);
	radix = ft_str_length(base_from);
	result = 0;
	minus = 1;
	while (is_space(*nbr))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
		if (*(nbr++) == '-')
			minus *= -1;
	while (resolve_base(base_from, *nbr) != NO_MATCH)
	{
		result *= radix;
		result += resolve_base(base_from, *nbr);
		nbr++;
	}
	if (result == 0)
		minus = 1;
	return (ft_buffer_base(base_to, result, neg(minus)));
}
