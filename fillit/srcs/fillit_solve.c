/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:29:05 by npimenof          #+#    #+#             */
/*   Updated: 2019/11/07 13:37:20 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*new_grid(int nb)
{
	int		i;
	int		j;
	char	*grid;

	i = 0;
	grid = (char *)malloc(sizeof(char) * (nb * nb + nb + 1));
	while (i < (nb * nb + nb))
	{
		j = 0;
		while (j < nb && i < nb * nb + nb)
		{
			grid[i] = '.';
			i++;
			j++;
		}
		grid[i] = '\n';
		i++;
	}
	grid[i] = 0;
	return (grid);
}

static int		test_bloc(int i, int size, char *grid, t_bloc *elem)
{
	if (i + (elem->x)[3] + ((elem->y)[3] * (size + 1)) > size * (size + 1))
		return (-1);
	if (i % (size + 1) + (elem->x)[3] > size)
		return (1);
	if (grid[i + (elem->x)[0] + ((elem->y)[0] * (size + 1))] != '.')
		return (1);
	if (grid[i + (elem->x)[1] + ((elem->y)[1] * (size + 1))] != '.')
		return (1);
	if (grid[i + (elem->x)[2] + ((elem->y)[2] * (size + 1))] != '.')
		return (1);
	if (grid[i + (elem->x)[3] + ((elem->y)[3] * (size + 1))] != '.')
		return (1);
	return (0);
}

static void		draw_bloc(int g_index, char *grid, t_bloc *elem, int size)
{
	int		i;
	char	c;

	i = 0;
	c = elem->c;
	if (grid[g_index + (elem->x)[i] + ((elem->y)[i] * (size + 1))] != '.')
		c = '.';
	while (i < 4)
	{
		grid[g_index + (elem->x)[i] + ((elem->y)[i] * (size + 1))] = c;
		i++;
	}
}

static int		put_bloc(char *grid, t_bloc *elem, int grid_size)
{
	int		i;
	int		ret;

	i = -1;
	while (grid[++i])
	{
		while (grid[i + (elem->x)[0]] != '.' && grid[i])
			i++;
		if ((ret = test_bloc(i, grid_size, grid, elem)) == 0)
		{
			if (elem->next == NULL)
			{
				draw_bloc(i, grid, elem, grid_size);
				return (0);
			}
			draw_bloc(i, grid, elem, grid_size);
			if (!put_bloc(grid, elem->next, grid_size) && elem->next != NULL)
				return (0);
			else
				draw_bloc(i, grid, elem, grid_size);
		}
		if (ret == -1)
			return (1);
	}
	return (1);
}

char			*solve(int blocs, t_bloc *start)
{
	int		min;
	int		max;
	char	*grid;

	min = ft_sqrt(blocs * 4);
	max = blocs * 4;
	while (min <= max)
	{
		grid = new_grid(min);
		if (put_bloc(grid, start->next, min) == 0)
			return (grid);
		free(grid);
		grid = NULL;
		min++;
	}
	return (0);
}
