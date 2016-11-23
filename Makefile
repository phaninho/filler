# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stmartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/12 22:04:11 by stmartin          #+#    #+#              #
#    Updated: 2016/07/21 07:50:20 by stmartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/
LIB_PATH = ./

SRC_NAME = ft_printf.c ft_putchar.c ft_putstr.c ft_itoa.c ft_strchr.c \
		   ft_strdup.c ft_putnbr.c ft_printunsigned.c ft_putoctal.c \
		   ft_strrev.c ft_puthexa.c ft_itox.c ft_strlen.c ft_toupper.c \
		   ft_strcpy.c ft_longint_convert.c ft_intsize.c ft_strupper.c \
		   ft_putnbri.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME =
NAME = libftprintf.a

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -fv $(OBJ)

fclean: clean
	@rm -fv $(NAME)
	@rm -rf $(OBJ_PATH)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
