# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 16:41:38 by npimenof          #+#    #+#              #
#    Updated: 2020/01/13 11:53:16 by npimenof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRCS = srcs/ft_printf.c srcs/process_format.c\
		srcs/flags/dash_flag.c srcs/flags/hash_flag.c srcs/flags/plus_flag.c\
		srcs/flags/spac_flag.c srcs/flags/zero_flag.c\
		srcs/specifiers/b_specifier.c srcs/specifiers/c_specifier.c\
		srcs/specifiers/f_specifier.c srcs/specifiers/i_specifier.c\
		srcs/specifiers/inv_specif.c srcs/specifiers/o_specifier.c\
		srcs/specifiers/p_specifier.c srcs/specifiers/s_specifier.c\
		srcs/specifiers/u_specifier.c srcs/specifiers/x_specifier.c\
		srcs/utilities/ft_fndigits.c srcs/utilities/get_type.c\
		srcs/utilities/parse_float.c srcs/utilities/read_flags.c\
		srcs/utilities/ft_memjoin.c

OBJS = ft_printf.o process_format.o\
		dash_flag.o hash_flag.o plus_flag.o\
		spac_flag.o zero_flag.o\
		b_specifier.o c_specifier.o\
		f_specifier.o i_specifier.o\
		inv_specif.o o_specifier.o\
		p_specifier.o s_specifier.o\
		u_specifier.o x_specifier.o\
		ft_fndigits.o get_type.o\
		parse_float.o read_flags.o\
		ft_memjoin.o

LIBFTOBJS = ft_putendl.o ft_putstr.o ft_putchar.o ft_strdup.o ft_strjoin.o\
			ft_strlen.o ft_strnew.o ft_memset.o ft_strchr.o ft_strdel.o\
			ft_strsub.o ft_strcspn.o ft_strspn.o ft_putnbr.o ft_itoa.o\
			ft_splitdigits.o ft_ndigits.o ft_atoi.o ft_isdigit.o\
			ft_iswhitespace.o ft_abs.o ft_fabs.o ft_strncpy.o\
			ft_creplace.o ft_cnreplace.o ft_toupper.o ft_pow_e.o\
			ft_itoa_base.o ft_memmove.o ft_strrchr.o ft_nchars.o\
			ft_sign.o ft_memcpy.o ft_del_args.o ft_ignore_neg.o\
			ft_lfmod.o ft_lstnew.o

INCL = ./includes

all: $(NAME)

$(NAME): $(SRCS)
	make -C ./libft
	gcc $(FLAGS) -c $(SRCS) -I$(INCL) -I./libft/includes
	ar -x libft/libft.a $(LIBFTOBJS)
	ar rc $(NAME) $(OBJS) $(LIBFTOBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS) $(LIBFTOBJS) "__.SYMDEF SORTED"
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all