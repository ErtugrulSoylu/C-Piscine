/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 00:38:28 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/15 20:35:35 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_stdin(void)
{
	int		size;
	char	buffer[100];
	int		file_desc;

	while (1)
	{
		size = read(0, buffer, 100);
		if (size > 0)
		{
			buffer[size - 1] = 0;
			file_desc = open(buffer, O_RDONLY);
			if (file_desc < 0)
				error();
			else if (init(file_desc))
			{
				write(1, "\n", 1);
				error();
			}
			write(1, "\n", 1);
		}
	}
}

int	iter_paths(char **paths, int size)
{
	int	i;
	int	err;
	int	file_desc;

	i = -1;
	err = 0;
	while (++i < size)
	{
		file_desc = open(paths[i], O_RDONLY);
		if (file_desc < 0 || init(file_desc))
		{
			err = 1;
			error();
		}
		if (i + 1 < size)
			write(1, "\n", 1);
	}
	return (err);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_stdin();
	return (iter_paths(argv + 1, argc - 1));
}
