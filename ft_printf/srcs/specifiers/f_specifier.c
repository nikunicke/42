/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:53:59 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 12:28:09 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*f_specifier(va_list a_list, t_conv_data *data)
{
	long double	n;
	int			precision;
	char		*res;

	if (data->precision)
		precision = ft_atoi(data->precision);
	else
		precision = 6;
	if (ft_strchr(data->flags, 'L'))
		n = va_arg(a_list, long double);
	else
		n = va_arg(a_list, double);
	res = ft_print_float(n, precision, data);
	data->size = ft_strlen(res);
	return (res);
}
