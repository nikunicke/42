/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:07:54 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/15 13:41:49 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define SIZE 256

void	ft_putstr(char *str, int fd)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

int		display_file(char *filename)
{
	int		fd;
	char	buf[SIZE];
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((i = read(fd, buf, SIZE)))
		write(1, buf, i);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr("File name missing.\n", 2);
		return (1);
	}
	if (ac > 2)
	{
		ft_putstr("Too many arguments.\n", 2);
		return (1);
	}
	else
	{
		if (!display_file(av[1]))
			return (1);
	}
	return (0);
}
