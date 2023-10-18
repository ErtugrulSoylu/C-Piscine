/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:46:13 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/16 19:46:14 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i] != '\0')
	{
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

void	write_nbr_base(long nbr, char *base, int length)
{
	if (nbr >= length)
	{
		write_nbr_base(nbr / length, base, length);
	}
	write(1, base + (nbr % length), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		length;
	int		index;
	int		*i;
	long	nb;

	nb = (long) nbr;
	index = 0;
	i = &index;
	if (check(base) != 0)
	{
		if (nb < 0)
		{
			nb *= -1;
			write(1, "-", 1);
		}
		length = ft_strlen(base);
		write_nbr_base(nb, base, length);
	}
}
/*
int    main(int ac, char **av)
{
    if (ac == 2)
        ft_putnbr_base(-2147483648, av[1]);
    write(1, "\n", 1);
    return (0);
}
*/
