# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2015/11/30 16:50:41 by ckupfers     #+#   ##    ##    #+#        #
#    Updated: 2018/07/03 18:32:14 by brobicho    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
NAME = ft_ls
FLAGS = -Wall -Wextra -Werror
SRC = \
	main.c \
	ft_ls.c \
	tri_t.c \
	ft_tools.c \
	ft_check.c \
	ft_init.c \
	ft_entry.c \
	print_opt_l.c \
	ft_error.c \
	print_min_maj.c \
	ft_free.c \
	ft_print.c

SRCO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft $(SRCO)
	@gcc -o $(NAME) $(FLAGS) $(SRCO) libft/libft.a

%.o: %.c
		@echo "Building : $<"
		@gcc $(FLAGS) -I . -I libft -c $<

libft:
	@make -C libft

clean:
	@rm -f $(SRCO)
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
