/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:21:10 by esoylu            #+#    #+#             */
/*   Updated: 2021/11/29 20:28:16 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);
void	rush04(int x, int y);

void	rush(int x, int y)
{
    rush00(x, y);
    rush01(x, y);
    rush02(x, y);
    rush03(x, y);
	rush04(x, y);
}

int	main(void)
{
	rush(3, 5);
	return (0);
}
