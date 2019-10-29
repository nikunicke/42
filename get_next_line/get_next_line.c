/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:35:41 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/29 19:40:21 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		open_file(char *filename)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	return (fd);
}

int		trim_line(char **pos, char **line, int ret, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (pos[fd][i] && pos[fd][i] != '\n')
		i++;
	if (pos[fd][i] == '\n')
	{
		*line = ft_strsub(pos[fd], 0, i);
		tmp = ft_strdup(pos[fd] + i + 1);
		free(pos[fd]);
		pos[fd] = tmp;
	}
	else if (pos[fd][i] == '\0')
	{
		*line = ft_strsub(pos[fd], 0, i);
		ft_strdel(&pos[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*pos[FD_MAX];

	if (!line || fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!pos[fd])
			pos[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(pos[fd], buf);
			free(pos[fd]);
			pos[fd] = tmp;
		}
		if (ft_strchr(pos[fd], '\n'))
			break ;
	}
	if (ret == 0 && (pos[fd] == NULL || pos[fd][0] == '\0'))
		return (0);
	return (trim_line(pos, line, ret, fd));
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			ft_putstr(line);
			free(line);
			ft_putchar('\n');
		}
		close(fd);
	}
	return (0);
}
