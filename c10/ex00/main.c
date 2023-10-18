/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:52:36 by esoylu            #+#    #+#             */
/*   Updated: 2021/12/10 10:47:39 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>

int	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
	return (0);
}

int	display_file(char *path)
{
	int				file;
	unsigned int	ret;
	char			buffer[1024];

	file = open(path, O_RDONLY);
	if (file < 0)
		return (0);
	while (1)
	{
		ret = read(file, buffer, 1024);
		if (ret == (unsigned int)-1 || ret <= 0)
			return (1);
		write(1, &buffer[0], ret);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (ft_putstr("File name missing.\n"));
	if (argc > 2)
		return (ft_putstr("Too many arguments.\n"));
	if (!display_file(argv[1]))
		return (ft_putstr("Cannot read file.\n"));
	return (0);
}
