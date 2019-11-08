/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:27:50 by npimenof          #+#    #+#             */
/*   Updated: 2019/11/07 13:53:57 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "get_next_line.h"

typedef struct		s_temp
{
	int				i;
	int				j;
	int				dot;
	int				hash1;
	int				hash2;
}					t_temp;

typedef struct		s_bloc
{
	struct s_bloc	*next;
	char			*str;
	char			c;
	int				origo_xy[2];
	int				x[4];
	int				y[4];
	int				bloc_nr;
}					t_bloc;

void				del_blocs(t_bloc **start);
void				create_list(int fd, t_bloc **bloc_start);
void				ft_blociter(t_bloc *lst, void (*f)(t_bloc *elem,
						t_temp *val));
void				validate_bloc(t_bloc *elem, t_temp *val);
int					count_blocs(t_bloc *elem);
char				*solve(int blocs, t_bloc *start);
int					read_input_file(char *file, int fd);
void				exitnow(int i);

#endif
