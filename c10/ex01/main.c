/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:08:37 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/10 10:47:09 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libgen.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

void	ft_putstr(int file_desc, char *str)
{
	while (*str != '\0')
		write(file_desc, str++, 1);
}

void	err(char *exec, char *path)
{
	if (errno == 0)
		return ;
	ft_putstr(2, basename(exec));
	ft_putstr(2, ": ");
	ft_putstr(2, path);
	ft_putstr(2, ": ");
	ft_putstr(2, strerror(errno));
	ft_putstr(2, "\n");
	errno = 0;
}

void	cat(char *exec, char *path, int file_desc)
{
	unsigned int	ret;
	char			buffer[1024];

	while (true)
	{
		ret = read(file_desc, buffer, 1024);
		if (ret <= 0)
			break ;
		if (errno != 0)
		{
			err(exec, path);
			break ;
		}
		write(1, &buffer[0], ret);
	}
	if (file_desc > 2)
		close(file_desc);
}

bool	iterate(char **paths, int size)
{
	int		file_desc;
	bool	ret;
	int		index;

	index = 1;
	ret = true;
	while (index < size)
	{
		file_desc = open(paths[index], O_RDONLY);
		if (file_desc < 0)
		{
			err(paths[0], paths[index]);
			ret = false;
		}
		else
			cat(paths[0], paths[index], file_desc);
		index++;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		cat(NULL, NULL, 0);
	else if (!iterate(argv, argc))
		return (1);
	return (0);
}
