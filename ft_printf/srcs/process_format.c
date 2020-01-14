/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:00:34 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 12:12:54 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static t_action	g_conv[] = {
	{ 'i', i_specifier },
	{ 'c', c_specifier },
	{ 'd', i_specifier },
	{ 'u', u_specifier },
	{ 's', s_specifier },
	{ 'f', f_specifier },
	{ 'x', x_specifier },
	{ 'X', x_specifier },
	{ 'o', o_specifier },
	{ 'p', p_specifier },
	{ 'b', b_specifier },
	{ '\0', inv_specif }
};

static t_action	g_flags[] = {
	{ '#', hash_flag },
	{ '+', plus_flag },
	{ ' ', spac_flag },
	{ '0', zero_flag },
	{ '-', dash_flg1 },
	{ '\0', NULL }
};

static int		ft_index_of(char c, t_action *arr)
{
	int		i;

	i = 0;
	while (arr[i].spec)
	{
		if (arr[i].spec == c)
			return (i);
		i++;
	}
	return (i);
}

static char		*exec_flags(t_conv_data *data, char *s)
{
	char	*pad;
	int		i;
	int		n;

	if (!data->flags)
		return (ft_strnew(0));
	n = 0;
	i = ft_strlen(data->flags);
	n = ft_ignore_neg(ft_atoi(data->width) - data->size);
	if (!(pad = ft_strnew(n + 2)))
		return (NULL);
	ft_memset(pad, ' ', n);
	while (i-- > 0)
	{
		if (ft_strspn(&data->flags[i], "Llh") != 0)
			continue;
		pad = g_flags[ft_index_of(data->flags[i], g_flags)].f(pad, n, data, s);
	}
	return (pad);
}

static t_list	*type_nav(t_conv_data *data, va_list a_list)
{
	char	*str;
	char	*pad;
	char	*out;
	t_list	*area;

	if (!(str = g_conv[ft_index_of(data->specifier, g_conv)].f(a_list, data)))
		return (NULL);
	if (!(pad = exec_flags(data, str)))
		return (NULL);
	if (ft_strchr(data->flags, '-'))
		str = dash_flg2(str, pad, data);
	if (ft_strchr(pad, '&'))
		pad[ft_strcspn(pad, "&")] = ' ';
	if (!(out = ft_memjoin(pad, str, ft_strlen(pad), data->size)))
		return (NULL);
	if (!(area = ft_lstnew(out, ft_strlen(pad) + data->size)))
		return (NULL);
	ft_del_args(3, str, pad, out);
	return (area);
}

static t_list	*type_conversion(char *part, va_list a_list)
{
	size_t				index;
	t_conv_data			*data;
	t_list				*area;
	char				*conv_res;
	char				*rest;

	if (!part[ft_strspn(part, FLAGS)])
		return (ft_lstnew(NULL, 0));
	if (!(data = read_flags(part, a_list)))
		return (NULL);
	index = ft_strspn(part, FLAGS) + 1;
	rest = ft_strsub(&part[index], 0, ft_strcspn(&part[index], "%"));
	if (!(area = type_nav(data, a_list)))
		return (NULL);
	if (!(conv_res = ft_memjoin(area->content, rest,
							area->content_size, ft_strlen(rest))))
		return (NULL);
	area->content_size += ft_strlen(rest);
	free(area->content);
	area->content = conv_res;
	data->size = 0;
	ft_del_args(5, rest, data->flags, data->precision, data->width, data);
	return (area);
}

t_list			*process_format(const char *format, va_list a_list)
{
	t_list	*conv_res;
	t_list	*out;
	char	*part;
	char	*tmp1;
	char	*tmp2;

	if (!(out = ft_lstnew(format, ft_strcspn(format, "%"))))
		return (NULL);
	part = (char *)format;
	while ((tmp1 = ft_strchr(part, '%')))
	{
		if (!(conv_res = type_conversion(tmp1 + 1, a_list)))
			return (NULL);
		if (!(tmp2 = ft_memjoin(out->content, conv_res->content,
							out->content_size, conv_res->content_size)))
			return (NULL);
		out->content_size += conv_res->content_size;
		ft_del_args(3, conv_res->content, conv_res, out->content);
		out->content = tmp2;
		if (tmp1[ft_strspn(tmp1 + 1, FLAGS) + 1] == '%')
			part = tmp1 + ft_strspn(tmp1 + 1, FLAGS) + 2;
		else
			part = tmp1 + 1;
	}
	return (out);
}
