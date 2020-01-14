/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:59:48 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 12:42:51 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*p_specifier(va_list a_list, t_conv_data *data)
{
	unsigned long long	n;
	char				*out;
	char				*pad;
	char				*res;
	int					i;

	n = va_arg(a_list, unsigned long long);
	out = ft_itoa_base(n, 16);
	i = ft_ignore_neg(ft_atoi(data->precision) - ft_strlen(out) + 2);
	if (!(pad = ft_strnew(i + 2)))
		return (NULL);
	ft_memset(pad, '0', i);
	ft_strncpy(pad, "0x", 2);
	res = ft_strjoin(pad, out);
	data->size = ft_strlen(res);
	ft_del_args(2, pad, out);
	return (res);
}
