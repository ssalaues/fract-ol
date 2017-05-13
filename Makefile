# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/05 15:05:07 by ssalaues          #+#    #+#              #
#    Updated: 2017/03/24 17:47:06 by ssalaues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

GF = -framework OpenGL -framework Appkit

FLAGS = -Ofast -ffast-math -m64 -g

LIBS = -lpthread -lmlx -lft -L./mlx -L./libft ./tp_lib/libftthread

SRCS = \
		./srcs/main.c			\
		./srcs/mandelbrot.c		\
		./srcs/julia.c			\
		./srcs/colors.c			\
		./srcs/mlx_rgb.c		\
		./srcs/tools.c

all: $(NAME)

$(NAME): minilx lib tp
	@clang $(SRCS) $(GF) $(LIBS) -o $(NAME) $(FLAGS)

lib:
	@make -C libft

minilx:
	@make -C mlx

tp:
	@make -C tp_lib

clean:
	@cd libft && make clean
	@cd srcs && /bin/rm -f $(SRCS:.c=.o)

fclean: clean
	@cd libft && make fclean
	@cd mlx && make clean
	@/bin/rm -f $(NAME)

re: fclean all
