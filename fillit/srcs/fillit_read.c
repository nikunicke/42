/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:00:05 by npimenof          #+#    #+#             */
/*   Updated: 2019/11/07 13:37:22 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bloc	*ft_create_bloc(char *bloc, char c)
{
	t_bloc		*temp;

	if (!(temp = (t_bloc *)malloc(sizeof(t_bloc))))
		return (NULL);
	temp->str = ft_strdup(bloc);
	temp->c = c + 1;
	free(bloc);
	temp->next = NULL;
	return (temp);
}

static void		check(char *line, char *bloc)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#')
			exitnow(1);
		i++;
	}
	if (i != 4)
		exitnow(1);
	free(line);
	free(bloc);
}

int				read_input_file(char *file, int fd)
{
	int			ret;
	char		buf[550];
	int			i;

	if (fd < 0)
		exitnow(1);
	if ((ret = read(fd, buf, 550)) > 0)
	{
		i = 0;
		if (ret < 20 || ret > 545)
			exitnow(1);
		if (buf[ret - 1] != '\n')
			exitnow(1);
	}
	else
		exitnow(1);
	close(fd);
	if ((fd = open(file, O_RDONLY)) < 0)
		exitnow(1);
	return (fd);
}

void			create_list(int fd, t_bloc **bloc_start)
{
	int			row;
	char		*tmp;
	char		*line;
	char		*bloc;
	t_bloc		*bloc_node;

	*bloc_start = ft_create_bloc((ft_strdup("Tervetuloa")), 'A' - 2);
	bloc_node = *bloc_start;
	row = 0;
	while ((ft_get_next_line(fd, &bloc)) > 0)
	{
		row++;
		if (row > 1 && bloc[0] != '\0')
			exitnow(1);
		while ((row + 1) % 5 != 0)
		{
			ft_get_next_line(fd, &line);
			tmp = ft_strjoin(bloc, line);
			check(line, bloc);
			bloc = tmp;
			row++;
		}
		bloc_node->next = ft_create_bloc(bloc, bloc_node->c);
		bloc_node = bloc_node->next;
	}
}
