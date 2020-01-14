/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:02:28 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 12:15:52 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*dash_flg1(char *str, size_t len, t_conv_data *data, char *s2)
{
	char	*hold;

	hold = data->flags;
	hold = s2;
	len = 0;
	if (str[0] == '0')
		len++;
	ft_creplace(&str[len], "0 ", ' ');
	return (str);
}

char	*dash_flg2(char *str, char *pad, t_conv_data *data)
{
	int		len;
	char	*left_pad;

	len = ft_strlen(pad) - ft_strlen(ft_creplace(pad, " ", '\0'));
	data->size += len;
	if (!(left_pad = ft_strnew(data->size)))
		return (str);
	ft_memset(left_pad, ' ', data->size);
	ft_strncpy(left_pad, str, data->size - len);
	ft_strdel(&str);
	str = left_pad;
	return (str);
}
