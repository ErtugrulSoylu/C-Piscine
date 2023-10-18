/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 03:03:19 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/12 03:03:20 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	x;

	i = 0;
	if (!(to_find[0]))
	{
		return (str);
	}
	while (str[i])
	{
		x = 0;
		while (str[i + x] == to_find[x] && str[i + x] != '\0')
		{
			if (!(to_find[x + 1]))
			{
				return (&str[i]);
			}
			x++;
		}
		i++;
	}
	return (0);
}
