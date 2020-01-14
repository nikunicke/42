/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:23:15 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 12:27:16 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*c_specifier(va_list a_list, t_conv_data *data)
{
	char	*c;

	data->size = 1;
	if (!(c = ft_strnew(1)))
		return (NULL);
	*c = (char)va_arg(a_list, int);
	return (c);
}
