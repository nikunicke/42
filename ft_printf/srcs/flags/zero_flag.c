/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:57:39 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/14 11:34:21 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	handle_p(char *str, size_t len, char *s2)
{
	if (len == 1)
		ft_memmove(s2 + 1, s2 + 2, ft_strlen(s2) - 1);
	else
		s2[1] = '0';
	str[1] = 'x';
}

char		*zero_flag(char *str, size_t len, t_conv_data *data, char *s2)
{
	if (!ft_strchr(SPECIFIERS, data->specifier) && !ft_strchr(data->flags, '-'))
		str = ft_cnreplace(str, "xX+-&", '0');
	if (data->specifier != 'f' && data->precision)
		return (str);
	if (ft_strcspn(data->flags, "-") != ft_strlen(data->flags) || !len)
	{
		if (*s2 == '-' && len && data->specifier != 's')
		{
			*str = '-';
			s2 = ft_memmove(s2, s2 + 1, ft_strlen(s2));
			s2[ft_strlen(s2)] = ' ';
		}
		return (str);
	}
	str = ft_cnreplace(str, "xX+-&", '0');
	if (*s2 == '-' && data->specifier != 's')
	{
		*str = '-';
		*s2 = '0';
	}
	if (data->specifier == 'p')
		handle_p(str, len, s2);
	return (str);
}
