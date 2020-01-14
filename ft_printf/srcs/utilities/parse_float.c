/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:09:01 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 12:29:38 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_splitdigits_lf(long double n, int len, char *s)
{
	if (n > 9)
	{
		ft_splitdigits_lf(n / 10, len - 1, s);
		s[len] = (unsigned long long)ft_lfmod(n, 10) + '0';
	}
	else
		s[len] = (unsigned long long)(n + '0');
}

static void	*ft_lftoa(long double n)
{
	long double	nb;
	char		*num;
	int			len;

	nb = n;
	len = 0;
	if (n < 0)
	{
		len++;
		nb *= -1;
	}
	len += ft_fndigitis(nb);
	if (!(num = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		num[0] = '-';
	ft_splitdigits_lf(nb, len - 1, num);
	return (num);
}

static int	ft_round(long double n, char *str, int len)
{
	int		index;

	if (n * 10 >= 5)
	{
		if (len <= 0)
			return (-1);
		index = len - 1;
		while (len-- && str[index] + 1 > '9')
			str[index--] = '0';
		if (str[index] != '.')
			str[index]++;
		len--;
	}
	return (len);
}

static int	fraction_tostr(long double n, int precision, char *fraction)
{
	unsigned long long	integer;
	unsigned long long	tmp;
	int					index;

	n = ft_fabs(n);
	integer = n;
	n -= integer;
	index = 1;
	while (precision--)
	{
		fraction[0] = '.';
		n *= 10;
		tmp = n;
		n -= tmp;
		fraction[index] = tmp + '0';
		index++;
	}
	if (ft_round(n, fraction, ft_strlen(fraction)) < 0)
		return (1);
	return (0);
}

char		*ft_print_float(long double n, int prec, t_conv_data *data)
{
	char	*integer;
	char	*fraction;
	char	*result;

	if (!(fraction = ft_strnew(prec + 1)))
		return (NULL);
	if (ft_strchr(data->flags, '#') && prec == 0)
		fraction[0] = '.';
	else if (fraction_tostr(n, prec, fraction))
	{
		if (n < 0)
			n--;
		else
			n++;
	}
	integer = ft_lftoa(n);
	result = ft_strjoin(integer, fraction);
	ft_strdel(&integer);
	ft_strdel(&fraction);
	return (result);
}
