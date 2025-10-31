# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 19:20:27 by hwakatsu          #+#    #+#              #
#    Updated: 2025/10/31 18:21:16 by hwakatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCDIR = .

SRCS =		flag_check.c \
			ft_itoa_base.c \
			ft_printf.c \
			printf_helper.c \
			put_printf.c \
			space_zero_print.c \
			specifier_cs_per.c \
			specifier_di.c \
			specifier_p.c \
			specifier_u.c \
			specifier_x_upper .c \
			specifier_x.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all bonus clean fclean re
