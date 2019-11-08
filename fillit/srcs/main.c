/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:26:36 by npimenof          #+#    #+#             */
/*   Updated: 2019/11/07 13:37:23 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_blocs(t_bloc *elem)
{
	int		blocs;

	blocs = 0;
	while (elem->next != NULL)
	{
		elem = elem->next;
		blocs++;
	}
	return (blocs);
}

t_temp		*set_values(void)
{
	t_temp	*val;

	val = malloc(sizeof(t_temp));
	val->i = 0;
	val->dot = 0;
	val->hash1 = 0;
	val->hash2 = 0;
	val->j = 0;
	return (val);
}

void		ft_blociter(t_bloc *lst, void (*f)(t_bloc *elem, t_temp *val))
{
	t_bloc	*tmp;
	t_temp	*val;

	val = NULL;
	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			val = set_values();
			f(tmp, val);
			free(val);
			val = NULL;
			tmp = tmp->next;
		}
	}
}

void		del_blocs(t_bloc **start)
{
	t_bloc	*tmp;

	while (*start)
	{
		tmp = *start;
		*start = (*start)->next;
		free(tmp->str);
		tmp->str = NULL;
		free(tmp);
		tmp = NULL;
	}
}

int			main(int ac, char **av)
{
	int		fd;
	t_bloc	*bloc_start;
	char	*result;
	int		blocs;

	bloc_start = NULL;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			exitnow(1);
		fd = read_input_file(av[1], fd);
		create_list(fd, &bloc_start);
		ft_blociter(bloc_start->next, validate_bloc);
		if ((blocs = count_blocs(bloc_start)) < 1 || blocs > 26)
			exitnow(1);
		result = solve(blocs, bloc_start);
		del_blocs(&bloc_start);
		ft_putstr(result);
		free(result);
		close(fd);
	}
	else
		exitnow(0);
	return (0);
}
