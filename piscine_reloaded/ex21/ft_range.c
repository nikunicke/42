/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 08:49:04 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/15 08:57:31 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*arr;
	int		tmp;
	int		i;

	if (min >= max)
		return (0);
	if (!(arr = malloc(sizeof(int) * max - min)))
		return (0);
	i = 0;
	tmp = min;
	while (i < max - min)
	{
		arr[i] = tmp;
		tmp++;
		i++;
	}
	return (arr);
}
