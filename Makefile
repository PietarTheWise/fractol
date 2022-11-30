# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/27 16:41:37 by kprytkov          #+#    #+#              #
#    Updated: 2022/06/21 15:51:47 by pnoutere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

FLAG = -Wall -Werror -Wextra -O3

SRC = main.c mouse_controls.c color.c keyboard_controls.c drawing_utils.c init_funcs.c celtic_multi.c weird_duck_multi.c juliaset_multi.c julia_and_mandle.c mandlebrot_multi.c burning_ship.c burning_ship_multi.c

SRO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRO)
	make -C ./libft/
	$(CC) $(FLAG) $(SRC) -lmlx -framework OpenGL -framework Appkit ./libft/libft.a -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(FLAG) -c -o $@ $<

clean:
	make -C libft/ clean
	rm -f $(SRO)

fclean: clean
	make -C libft/ fclean
	rm -Rf $(NAME)

re: fclean all