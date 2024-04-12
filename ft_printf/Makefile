# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 16:17:29 by aboukezi          #+#    #+#              #
#    Updated: 2024/01/29 16:17:31 by aboukezi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #	

NAME = libftprintf.a

SRC =	ft_printf.c \
	ft_putchar.c\
	ft_putstr.c \
	ft_putnbr.c \
	ft_putunbr.c \
	ft_hex_num.c \
	ft_printhex.c \

OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) 
	$(AR) $(NAME) $(OBJ) 


%.o: %.c $(SRC)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
	
clean:
	$(RM) $(OBJ)


fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
