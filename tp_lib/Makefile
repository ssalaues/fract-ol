NAME = libthreadp

EX = tp_example

SRCS = \
		tp_lib.c

all: $(NAME)

$(NAME): lib 
	@clang -Wall -Wextra -Werror -c $(SRCS)
	@ar rcs $(NAME) $(SRCS:.c=.o)
	@echo "\033[34m SUCCESS\n"

example: lib
	@clang -Wall -Wextra -Werror -c $(SRCS) tp_ex.c
	clang $(SRCS:.c=.o) tp_ex.c -g -L../libft -lft -o $(EX) -pthread

lib:
	@make -C ../libft

clean:
	@make clean -C ../libft
	@/bin/rm -f $(SRCS:.c=.o)

fclean: clean
	@make fclean -C ../libft
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(EX)

re: fclean all
