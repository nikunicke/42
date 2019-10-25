# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 09:31:11 by npimenof          #+#    #+#              #
#    Updated: 2019/10/15 09:56:30 by npimenof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

OUTS = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

INCS = includes/

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I $(INCS) -c $(SRCS)
	ar rc $(NAME) $(OUTS)
	ranlib $(NAME)

clean:
	rm -f $(OUTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

