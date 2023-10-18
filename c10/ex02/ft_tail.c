/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:36:52 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/15 12:38:14 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int	main(int argc, char **argv)
{
	int		option;
	char	*str;

	if (argc < 2)
	{
		return (0);
	}
	option = ft_atoi(argv[2], 0);
	if (option == -1)
	{
		ft_illegal_offset(argv);
		return (0);
	}
	if (argc == 3)
	{
		ft_putstr(get_stdin(option));
	}
	else
		str = ft_write(argv, argc, option);
	return (0);
}
