/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_specif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:44:10 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 12:40:08 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*inv_specif(va_list a_list, t_conv_data *data)
{
	char	*str;
	va_list	a;

	va_copy(a, a_list);
	va_end(a);
	if (!(str = ft_strnew(1)))
		return (NULL);
	str[0] = data->specifier;
	if (data->specifier == 0)
		data->size = 0;
	else
		data->size = 1;
	return (str);
}
