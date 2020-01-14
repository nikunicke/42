/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:42:48 by npimenof          #+#    #+#             */
/*   Updated: 2020/01/13 11:55:42 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	*ft_memjoin(const void *s1, const void *s2, size_t len1, size_t len2)
{
	unsigned char	*a;
	unsigned char	*b;
	char			*res;

	if (!(len1 + len2) || !(res = ft_strnew(len1 + len2)))
		return (NULL);
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	ft_memcpy(res, s1, len1);
	ft_memcpy(res + len1, s2, len2);
	return (res);
}
