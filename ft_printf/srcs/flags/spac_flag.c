/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spac_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:01:22 by npimenof          #+#    #+#             */
/*   Updated: 2019/12/20 14:49:33 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*spac_flag(char *str, size_t len, t_conv_data *data, char *s2)
{
	int		i;

	if (*s2 == '-' || *str == '-' || ft_strchr(data->flags, '+'))
		return (str);
	if (data->specifier == 'i' || data->specifier == 'd' ||
		data->specifier == 'f')
	{
		i = 1;
		if (!(ft_strcspn(data->flags, "-0") >= ft_strlen(data->flags)))
			i = len;
		ft_strncpy(&str[ft_ignore_neg(len - i)], "&", 1);
	}
	return (str);
}
