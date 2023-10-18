/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:36:44 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/15 12:37:52 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_error(int fd, char **argv, int i)
{
	if (fd < 0)
	{
		ft_puterror(basename(argv[0]));
		ft_puterror(": ");
		ft_puterror(argv[i]);
		ft_puterror(": ");
		ft_puterror(strerror(errno));
		ft_puterror("\n");
		return (1);
	}
	return (0);
}

void	ft_banner(char **argv, int argc, int i)
{
	int	size;

	size = ft_strlen(argv[1]);
	if ((size >= 3 && argc > 3) || argc > 4)
	{
		ft_putstr("==> ");
		ft_putstr(argv[i]);
		ft_putstr(" <==");
		ft_putstr("\n");
	}
}

void	ft_illegal_offset(char **argv)
{
	ft_puterror(basename(argv[0]));
	ft_puterror(": ");
	ft_puterror("illegal offset -- ");
	ft_puterror(argv[2]);
	ft_puterror("\n");
}
