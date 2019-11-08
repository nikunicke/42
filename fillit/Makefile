# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 11:34:24 by npimenof          #+#    #+#              #
#    Updated: 2019/11/07 13:59:31 by npimenof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS1 = srcs/fillit_read.c srcs/fillit_solve.c srcs/fillit_validate.c srcs/main.c

OBJS = $(subst .c,.o,$(subst srcs/,,$(SRCS1)))

LIB = -L./libft -lft

INCL = -I ./srcs -I ./libft/includes/

all: libftmake
	gcc $(FLAGS) -c $(SRCS1) $(INCL)
	gcc $(FLAGS) $(INCL) $(OBJS) $(LIB) -o $(NAME)

libftmake:
	make -C libft
	
clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: clean all