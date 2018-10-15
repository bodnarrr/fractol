# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abodnar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/16 12:17:53 by abodnar           #+#    #+#              #
#    Updated: 2018/05/22 12:21:33 by abodnar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIB = libftprintf.a

MLX = libmlx.a

SRCS =	main.c

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADERS = *.h

all: $(NAME)

%.o : %.c
	@gcc -I. -I./libftprintf -I./minilibx_macos $(FLAGS) -c $< -o $@

$(NAME): $(LIB) $(MLX) $(OBJECTS) $(HEADERS)
	@gcc -framework OpenGL -framework AppKit -o $@ -I. -I./libftprintf -I./minilibx_macos $(OBJECTS) $(LIB) $(MLX)
	@echo "\033[1;32mFractol is ready\033[0m"

$(LIB):
	@make -C ./libftprintf/
	@cp ./libftprintf/libftprintf.a .

$(MLX):
	make -C ./minilibx_macos
	cp ./minilibx_macos/libmlx.a .

clean:
	@make fclean -C ./libftprintf
	@rm -f *.o
	@rm -f minilibx_macos/*.o
	@rm -f libftprintf.a
	@rm -f libmlx.a
	@echo "\033[1;32mObject files were removed\033[0m"

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re