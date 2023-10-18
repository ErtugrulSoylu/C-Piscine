/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:40:17 by esoylu            #+#    #+#             */
/*   Updated: 2021/11/29 20:29:30 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	rush04(int x, int y)
{
    if(x < 1 || y < 1) return 0;
	int	i;
	int	j;

	j = 1;
	while (j <= y)
	{
		i = 1;
		while (i <= x)
		{
			if (i == 1 && j == 1)
				ft_putchar('A');
			else if (i > 1 && i < x && j > 1 && j < y)
				ft_putchar(' ');
			else if ((i == 1 && j == y) || (i == x && j == 1))
				ft_putchar('C');
			else if (i == x && j == y)
				ft_putchar('A');
			else
				ft_putchar('B');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
