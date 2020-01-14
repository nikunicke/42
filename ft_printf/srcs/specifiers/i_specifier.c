/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:50:40 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 12:53:27 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*i_specifier(va_list a_list, t_conv_data *data)
{
	char		*num;
	char		*pad;
	char		*res;
	int			len;
	long long	n;

	n = va_arg(a_list, long long);
	get_type(&n, data);
	num = ft_itoa(n);
	if (data->precision && !ft_atoi(data->precision) && !n)
		num[0] = '\0';
	len = ft_ignore_neg(ft_atoi(data->precision) - ft_strlen(num) + 1);
	pad = ft_strnew(len);
	if (n < 0 && pad)
	{
		pad[0] = '-';
		ft_memmove(num, num + 1, ft_strlen(num));
		ft_memset(pad + 1, '0', len);
	}
	else
		ft_memset(pad, '0', ft_ignore_neg(len - 1));
	res = ft_strjoin(pad, num);
	data->size = ft_strlen(res);
	ft_del_args(2, num, pad);
	return (res);
}
