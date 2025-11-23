NAME = ft_ls
CC = gcc
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
	@$(CC) $(FLAGS) -o $(NAME) $(SRCO) libft/libft.a
	@echo "Build OK"

%.o: %.c
	@echo "Compiling: $<"
	@$(CC) $(FLAGS) -I . -I libft -c $<

libft:
	@$(MAKE) -C libft

clean:
	@rm -f $(SRCO)
	@$(MAKE) -C libft clean

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft

