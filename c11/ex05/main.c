/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:11:57 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/08 12:47:33 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	res;
	int	mult;

	mult = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	j = i;
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	while (i < j)
	{
		res += (str[(j--) - 1] - '0') * mult;
		mult *= 10;
	}
	return (res);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
	{
		c = nb + 48;
		write(1, &c, 1);
		return ;
	}
	else
		ft_putnbr(nb / 10);
	ft_putnbr(nb % 10);
}

void	div(int x, int y)
{
	if (y == 0)
		write(1, "Stop : division by zero", 23);
	else
		ft_putnbr(x / y);
}

void	mod(int x, int y)
{
	if (y == 0)
		write(1, "Stop : modulo by zero", 21);
	else
		ft_putnbr(x % y);
}

int	main(int argc, char **argv)
{
	int		fe;
	int		se;
	char	op;

	if (argc != 4)
		return (0);
	fe = ft_atoi(argv[1]);
	op = argv[2][0];
	se = ft_atoi(argv[3]);
	if (op == '\0')
		write(1, "0", 1);
	else if (op == '+')
		ft_putnbr(fe + se);
	else if (op == '-')
		ft_putnbr(fe - se);
	else if (op == '*')
		ft_putnbr(fe * se);
	else if (op == '/')
		div(fe, se);
	else if (op == '%')
		mod(fe, se);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
