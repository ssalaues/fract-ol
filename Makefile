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

NAME = fdf

SRCS = \
		main.c		\
		graphics.c

all: $(NAME)

$(NAME): lib mlx
	@cd srcs && clang -Wall -Wextra -Werror -c $(SRCS) -g
	cd srcs && clang $(SRCS:.c=.o) -g -L../mlx -lmlx -framework OpenGL -framework Appkit -L../libft -lft -o $(NAME)
	mv srcs/fdf .

lib:
	@cd libft && make

mlx:
	@cd minilibx && make

clean:
	@cd libft && make clean
	@cd srcs && /bin/rm -f $(SRCS:.c=.o)

fclean: clean
	@cd libft && make fclean
	@cd minilibx && make clean
	@/bin/rm -f $(NAME)

re: fclean all
