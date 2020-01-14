/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:26:02 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 12:43:29 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*u_specifier(va_list a_list, t_conv_data *data)
{
	char			*num;
	char			*pad;
	char			*res;
	int				len;
	unsigned int	n;

	n = va_arg(a_list, unsigned long long);
	get_type(&n, data);
	num = ft_itoa_base(n, 10);
	if (data->precision && !ft_atoi(data->precision) && !n)
		num[0] = '\0';
	len = ft_ignore_neg(ft_atoi(data->precision) - ft_strlen(num));
	pad = ft_strnew(len);
	ft_memset(pad, '0', len);
	res = ft_strjoin(pad, num);
	data->size = ft_strlen(res);
	ft_del_args(2, pad, num);
	return (res);
}
