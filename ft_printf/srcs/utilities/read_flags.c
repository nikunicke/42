/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:49:28 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 12:01:21 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static t_conv_data	*init_conversion_data(void)
{
	t_conv_data	*node;

	if (!(node = malloc(sizeof(t_conv_data))))
		return (NULL);
	node->specifier = 0;
	node->precision = NULL;
	node->flags = NULL;
	node->width = NULL;
	node->size = 0;
	return (node);
}

static int			get_precision(t_conv_data *data, char *str, va_list a_list)
{
	int		i;

	ft_strdel(&data->precision);
	if (*str == '*')
	{
		i = 1;
		data->precision = ft_itoa(va_arg(a_list, int));
	}
	else
	{
		i = ft_strspn(str, "0123456789");
		data->precision = ft_strsub(str, 0, i);
	}
	return (i);
}

static int			get_width(t_conv_data *data, char *str, va_list a_list)
{
	int		i;

	i = 1;
	if (ft_isdigit(*str) || *str == '*')
	{
		ft_strdel(&data->width);
		if (ft_isdigit(*str))
		{
			i = ft_strspn(str, "0123456789");
			data->width = ft_strsub(str, 0, i);
		}
		else
			data->width = ft_itoa(va_arg(a_list, int));
	}
	return (i);
}

static void			def_flags(t_conv_data *data, char *s, int n, va_list a_list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (s[i] == '.' && ++i)
			i += get_precision(data, &s[i], a_list);
		else
		{
			if (s[i] != '0' && (ft_isdigit(s[i]) || s[i] == '*'))
				i += get_width(data, &s[i], a_list);
			else
				data->flags[j++] = s[i++];
		}
	}
}

t_conv_data			*read_flags(char *str, va_list a_list)
{
	t_conv_data	*data;
	int			len;

	if (!(data = init_conversion_data()))
		return (NULL);
	len = ft_strspn(str, FLAGS);
	data->specifier = str[len];
	if (!(data->flags = ft_strnew(len)))
		return (NULL);
	def_flags(data, str, len, a_list);
	return (data);
}
