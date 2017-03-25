# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 09:10:49 by ssalaues          #+#    #+#              #
#    Updated: 2017/03/15 14:46:22 by ssalaues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := \
	ft_memset.c 	\
	ft_bzero.c 		\
	ft_memcpy.c 	\
	ft_memccpy.c 	\
	ft_memmove.c 	\
	ft_memchr.c 	\
	ft_memcmp.c 	\
	ft_strlen.c 	\
	ft_strdup.c 	\
	ft_strndup.c 	\
	ft_strcpy.c 	\
	ft_strncpy.c 	\
	ft_strcat.c 	\
	ft_strncat.c 	\
	ft_strlcat.c 	\
	ft_strchr.c 	\
	ft_strrchr.c 	\
	ft_strstr.c 	\
	ft_strnstr.c 	\
	ft_strcmp.c 	\
	ft_strncmp.c 	\
	ft_atoi.c 		\
	ft_isalpha.c 	\
	ft_isdigit.c 	\
	ft_isalnum.c 	\
	ft_isascii.c 	\
	ft_isprint.c 	\
	ft_toupper.c 	\
	ft_tolower.c 	\
	\
	ft_memalloc.c 	\
	ft_memdel.c 	\
	ft_strnew.c 	\
	ft_strdel.c 	\
	ft_strclr.c 	\
	ft_striter.c 	\
	ft_striteri.c 	\
	ft_strmap.c 	\
	ft_strmapi.c 	\
	ft_strequ.c 	\
	ft_strnequ.c 	\
	ft_strsub.c 	\
	ft_strjoin.c 	\
	ft_strtrim.c 	\
	ft_strsplit.c 	\
	ft_itoa.c 		\
	ft_putchar.c 	\
	ft_putstr.c 	\
	ft_putendl.c 	\
	ft_putnbr.c 	\
	ft_putchar_fd.c \
	ft_putstr_fd.c 	\
	ft_putendl_fd.c \
	ft_putnbr_fd.c 	\
	\
	ft_intlen.c 	\
	ft_abs.c 		\
	ft_wcount.c 	\
	ft_wordlen.c 	\
	ft_swap.c		\
	ft_atoi_array.c \
	ft_numct.c		\
	ft_countnline.c	\
	get_next_line.c	\
	\
	ft_lstnew.c 	\
	ft_lstdelone.c 	\
	ft_lstdel.c 	\
	ft_lstadd.c 	\
	ft_lstiter.c 	\
	ft_lstmap.c 

NAME = libft.a

CFLAGS += $(foreach SRCS,$(SRCS),-c -Wextra -Werror -Wall)

all: $(NAME)

$(NAME):
	@echo "\033[32m BUILDING LIB"
	@gcc $(SRCS) -c -Wextra -Werror -Wall
	@ar rcs $(NAME) $(SRCS:.c=.o)
	@echo "\033[34m SUCCESS\n"

clean:
	@echo "\033[35m Cleaning your mess"	
	@/bin/rm -rf $(SRCS:.c=.o)
	@echo "\033[34m DONE\n"

fclean: clean
	@echo "\033[31m Removing Compiled Lib"
	@/bin/rm -rf $(NAME)
	@echo "\033[34m DONE\n"

re: fclean all
