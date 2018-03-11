# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/13 16:02:56 by brobicho     #+#   ##    ##    #+#        #
#    Updated: 2018/03/01 15:36:49 by brobicho    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c ft_ls.c ft_list.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C include/libft/
	@gcc $(OBJ) -o $(NAME) -L include/libft -lft

clean:
	@make -C include/libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make fclean -C include/libft/

re: fclean all

.PHONY: all clean fclean re
