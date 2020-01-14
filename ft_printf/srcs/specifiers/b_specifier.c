/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:04:25 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 12:26:20 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*b_specifier(va_list a_list, t_conv_data *data)
{
	char				*out;
	char				*pad;
	char				*res;
	unsigned long long	n;
	int					i;

	n = va_arg(a_list, unsigned long long);
	get_type(&n, data);
	out = ft_itoa_base(n, 2);
	i = ft_ignore_neg(ft_atoi(data->precision) - ft_strlen(out));
	if (!(pad = ft_strnew(i)))
		return (NULL);
	ft_memset(pad, '0', i);
	res = ft_strjoin(pad, out);
	data->size = ft_strlen(res);
	ft_strdel(&pad);
	ft_strdel(&out);
	return (res);
}
