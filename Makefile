# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jcocteau <Jcocteau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 06:05:44 by Jcocteau          #+#    #+#              #
#    Updated: 2018/01/07 10:19:48 by Jcocteau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME  =  fractol
SRC   = src/juliaSet.c src/mandelbroSet.c src/main.c \
		
OBJ   	=  $(SRC:.c=.o)
HDR   	=  libft/includes/
MLX   	=  -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
FLAGS  	=  -Wall -Wextra -Werror
CC   	=  gcc

.SILENT:

%.o: %.c
	@$(CC) $(FLAGS) -I . -I /usr/X11/include/ -o $@ -c $? -g

all: $(NAME)

$(NAME): $(OBJ)
	@make -C minilibx_macos
	@make -C libft/ fclean && make -C libft/ && $(CC) $(FLAGS) -o $(NAME)\
		$(OBJ) libft/libft.a $(MLX)

clean:
	@rm -f $(OBJ)

cleanlib:
	@make -C minilibx_macos/ clean
	@make -C libft/ fclean

fclean: clean cleanlib
	@rm -f $(NAME)

re: fclean all
