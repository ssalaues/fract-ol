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

SRCS = \
		main.c			\
		mandelbrot.c	\
		colors.c		\
		mlx_rgb.c

all: $(NAME)

$(NAME): minilx lib
	@cd srcs && clang -Wall -Wextra -Werror -c $(SRCS) -O2
	@cd srcs && clang $(SRCS:.c=.o) -L../mlx -lmlx -framework OpenGL -framework Appkit -L../libft -lft -o $(NAME) -O2
	@mv srcs/$(NAME) .

lib:
	@make -C libft

minilx:
	@make -C mlx

clean:
	@cd libft && make clean
	@cd srcs && /bin/rm -f $(SRCS:.c=.o)

fclean: clean
	@cd libft && make fclean
	@cd mlx && make clean
	@/bin/rm -f $(NAME)

re: fclean all
