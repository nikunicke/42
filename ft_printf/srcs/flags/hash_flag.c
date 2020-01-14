/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:33:35 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/03 15:07:05 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*hash_flag(char *str, size_t len, t_conv_data *data, char *s2)
{
	int		i;
	char	*hold;

	hold = s2;
	i = 2;
	if (!ft_atoi(s2))
		return (str);
	if (ft_strcspn(data->flags, "0-") != ft_strlen(data->flags))
		i = len;
	if (data->specifier == 'x' || data->specifier == 'X')
	{
		if (data->specifier == 'X')
			ft_strncpy(&str[ft_ignore_neg(len - i)], "0X", 2);
		else
			ft_strncpy(&str[ft_ignore_neg(len - i)], "0x", 2);
	}
	if (data->specifier == 'o' && !ft_atoi(data->precision))
		ft_memcpy(&str[ft_ignore_neg(len - i + 1)], "0", 1);
	return (str);
}
