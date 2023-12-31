/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:27:00 by esoylu            #+#    #+#             */
/*   Updated: 2021/11/28 23:09:38 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < 32)
			return (0);
		str++;
	}
	return (1);
}
