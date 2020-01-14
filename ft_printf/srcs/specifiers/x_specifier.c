/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:24:36 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 12:45:09 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*x_specifier(va_list a_list, t_conv_data *data)
{
	char				*out;
	char				*pad;
	char				*res;
	int					i;
	unsigned long long	n;

	n = va_arg(a_list, unsigned long long);
	get_type(&n, data);
	out = ft_itoa_base(n, 16);
	if (data->specifier == 'X' && out)
	{
		i = 0;
		while (out[i])
		{
			out[i] = ft_toupper(out[i]);
			i++;
		}
	}
	i = ft_ignore_neg(ft_atoi(data->precision) - ft_strlen(out));
	pad = ft_strnew(i);
	ft_memset(pad, '0', i);
	res = ft_strjoin(pad, out);
	data->size = ft_strlen(res);
	ft_del_args(2, pad, out);
	return (res);
}
