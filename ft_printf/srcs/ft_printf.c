/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:15:59 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 13:31:15 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_printf(const char *format, ...)
{
	t_list		*output;
	int			len;
	va_list		a_list;

	if (!format || !*format)
		return (0);
	va_start(a_list, format);
	if (!(output = process_format(format, a_list)))
	{
		va_end(a_list);
		return (0);
	}
	len = output->content_size;
	write(1, output->content, len);
	ft_del_args(2, output->content, output);
	va_end(a_list);
	return (len);
}

char	*ft_saprintf(const char *format, ...)
{
	t_list		*output;
	int			len;
	va_list		a_list;
	char		*ret;

	if (!format || !*format)
		return (0);
	va_start(a_list, format);
	if (!(output = process_format(format, a_list)))
	{
		va_end(a_list);
		return (0);
	}
	len = output->content_size;
	if (!(ret = ft_strnew(len)))
		return (NULL);
	ft_memcpy(ret, output->content, len);
	ft_del_args(2, output->content, output);
	va_end(a_list);
	return (ret);
}
