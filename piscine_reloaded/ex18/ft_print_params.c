/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:20:57 by npimenof          #+#    #+#             */
/*   Updated: 2019/10/14 18:33:14 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			ft_putstr(av[i]);
			ft_putstr("\n");
			i++;
		}
	}
	return (0);
}
