/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fndigits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:12:09 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/03 15:41:13 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_fndigitis(long double n)
{
	int			count;

	if (n < 1)
		return (1);
	count = 0;
	while (n >= 1)
	{
		count++;
		n /= 10;
	}
	return (count);
}
