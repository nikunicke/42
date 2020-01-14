/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:01:52 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/03 14:53:57 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	signed_type(void *p, t_conv_data *data)
{
	long long	*a;
	int			ell;
	int			h;

	ell = ft_nchars(data->flags, 'l');
	h = ft_nchars(data->flags, 'h');
	a = p;
	if (ell)
	{
		if (ell % 2 == 0)
			*a = (long long)*a;
		else
			*a = (long)*a;
	}
	else if (h)
	{
		if (h % 2 == 0)
			*a = (char)*a;
		else
			*a = (short)*a;
	}
	else
		*a = (int)*a;
}

static void	unsigned_type(void *p, t_conv_data *data)
{
	unsigned long long	*a;
	int					ell;
	int					h;

	ell = ft_nchars(data->flags, 'l');
	h = ft_nchars(data->flags, 'h');
	a = p;
	if (ell)
	{
		if (ell % 2 == 0)
			*a = (unsigned long long)*a;
		else
			*a = (unsigned long)*a;
	}
	else if (h)
	{
		if (h % 2 == 0)
			*a = (unsigned char)*a;
		else
			*a = (unsigned short)*a;
	}
	else
		*a = (unsigned int)*a;
}

void		get_type(void *p, t_conv_data *data)
{
	if (data->specifier == 'i' || data->specifier == 'd')
		signed_type(p, data);
	if (data->specifier == 'u' || data->specifier == 'x' ||
		data->specifier == 'X' || data->specifier == 'o')
		unsigned_type(p, data);
}
