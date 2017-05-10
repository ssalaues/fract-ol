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

SRCS = \
		main.c			\
		mandelbrot.c	\
		colors.c		\
		mlx_rgb.c		\
		tools.c

all: $(NAME)

$(NAME): minilx lib tp
	@cd srcs && clang -Wall -Wextra -Werror -c $(SRCS) -Ofast -ffast-math -m64
	@cd srcs && clang $(SRCS:.c=.o) -L../mlx -lmlx -framework OpenGL -framework Appkit -L../libft -lft -L../tp_lib -ltp -o $(NAME) -Ofast -ffast-math
	@mv srcs/$(NAME) .

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
