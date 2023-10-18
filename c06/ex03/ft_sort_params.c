/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:22:25 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/13 17:44:43 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_string_tab(char **tab, int size)
{
	int		f;
	int		i;
	char	*tmp;

	f = 1;
	while (f)
	{
		f = 0;
		i = 0;
		while (++i < size)
		{
			if (ft_strcmp(tab[i], tab[i -1]) < 0)
			{
				f = 1;
				tmp = tab[i];
				tab[i] = tab[i -1];
				tab[i -1] = tmp;
			}
		}
	}
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **args)
{
	int	i;

	i = 0;
	if (argc > 1)
	{
		ft_sort_string_tab(&args[1], argc -1);
		while (++i < argc)
		{
			ft_putstr(args[i]);
			write(1, "\n", 1);
		}
	}
	return (0);
}
