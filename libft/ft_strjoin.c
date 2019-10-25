/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:52:24 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/24 10:45:51 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] || s2[j])
	{
		if (s1[i])
		{
			newstr[i] = s1[i];
			i++;
		}
		if (s2[j])
		{
			newstr[ft_strlen((char *)s1) + j] = s2[j];
			j++;
		}
	}
	return (newstr);
}
