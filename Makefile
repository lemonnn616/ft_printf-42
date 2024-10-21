# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 13:42:02 by iriadyns          #+#    #+#              #
#    Updated: 2024/10/21 15:51:50 by iriadyns         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_putchar_printf.c ft_putint_printf.c \
	  ft_putstr_printf.c ft_printf_utils.c ft_putptr_printf.c \
	  ft_putuint_printf.c ft_printf.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_utils_utils.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) test_ft_printf.o test_ft_printf

re: fclean all

.PHONY: all bonus fclean re clean
