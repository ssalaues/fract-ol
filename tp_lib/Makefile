N1 = lib_tp

EX = tp_example

SRCS = \
		tp_lib.c

all: $(N1)

$(N1): lib 
	@clang -Wall -Wextra -Werror -c $(SRCS)
	@ar rcs $(N1) $(SRCS:.c=.o)
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
	@/bin/rm -f $(N1)
	@/bin/rm -f $(EX)

re: fclean all
