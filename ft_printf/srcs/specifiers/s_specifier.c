/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:46:24 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 12:21:40 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*s_specifier(va_list a_list, t_conv_data *data)
{
	char	*str;
	char	*result;
	int		precision;

	if (!(str = ft_strdup(va_arg(a_list, char *))))
		str = ft_strdup("(null)");
	if (data->precision)
		precision = ft_atoi(data->precision);
	else
		precision = ft_strlen(str);
	if (!(result = ft_strnew(precision)))
		return (NULL);
	ft_memcpy(result, str, precision);
	data->size = ft_strlen(result);
	ft_strdel(&str);
	return (result);
}
