/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:07:05 by npimenof          #+#    #+#             */
/*   Updated: 2019/11/07 13:37:21 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			exitnow(int i)
{
	if (i == 1)
		ft_putendl("error");
	else
		ft_putendl("usage: ./fillit [ input_file ]");
	exit(1);
}

static void		bloc_origo(t_bloc *elem)
{
	int		i;

	(elem->origo_xy)[0] = 3;
	(elem->origo_xy)[1] = 3;
	i = 0;
	while (i < 4)
	{
		if ((elem->x[i]) < (elem->origo_xy)[0])
			(elem->origo_xy)[0] = (elem->x[i]);
		if ((elem->y[i]) < (elem->origo_xy)[1])
			(elem->origo_xy)[1] = (elem->y[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(elem->x)[i] = (elem->x)[i] - (elem->origo_xy)[0];
		(elem->y)[i] = (elem->y)[i] - (elem->origo_xy)[1];
		i++;
	}
}

static int		neighbours(int i, char c, char *str)
{
	int			total;

	total = 0;
	if (i - 4 >= 0 && (str[i - 4] == '#' || str[i - 4] == c))
		total++;
	if (i + 4 <= 15 && (str[i + 4] == '#' || str[i + 4] == c))
		total++;
	if (i % 4 == 0)
		if (i + 1 <= 15)
			if (str[i + 1] == '#' || str[i + 1] == c)
				total++;
	if (i % 4 == 3)
		if (i - 1 <= 15)
			if (str[i - 1] == '#' || str[i - 1] == c)
				total++;
	if (i % 4 == 1 || i % 4 == 2)
	{
		if (i + 1 <= 15)
			if (str[i + 1] == '#' || str[i + 1] == c)
				total++;
		if (i - 1 <= 15)
			if (str[i - 1] == '#' || str[i - 1] == c)
				total++;
	}
	return (total);
}

void			validate_bloc(t_bloc *elem, t_temp *val)
{
	while ((elem->str)[val->i])
	{
		if ((elem->str)[val->i] == '.')
			val->dot++;
		if (((elem->str)[val->i] == '#' || (elem->str)[val->i] == elem->c) &&
				neighbours(val->i, elem->c, elem->str) > 0)
		{
			if (val->j == 5)
				exitnow(1);
			elem->x[val->j] = val->i % 4;
			elem->y[val->j] = val->i / 4;
			val->j++;
			val->hash1++;
		}
		if (((elem->str)[val->i] == '#' || (elem->str)[val->i] == elem->c) &&
				neighbours(val->i, elem->c, elem->str) > 1)
			val->hash2++;
		val->i++;
	}
	if (val->i == 16 && val->dot == 12 && val->hash1 == 4 && val->hash2 >= 1)
	{
		bloc_origo(elem);
		return ;
	}
	exitnow(1);
}
