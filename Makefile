# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 19:20:27 by hwakatsu          #+#    #+#              #
#    Updated: 2025/11/04 07:59:52 by hwakatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCDIR = .
LIBFT_DIR = libft

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
			specifier_x_upper.c \
			specifier_x.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
bonus: all

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
