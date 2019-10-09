# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/30 20:33:43 by dvictor           #+#    #+#              #
#    Updated: 2019/10/07 17:19:33 by dvictor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
MAKE = make
FLAGS = -Wall -Wextra -Werror
SRCS = chk_and_mv.c coord.c validation.c move.c sw_grid.c sw_recursive.c sw_startgrid.c validbleat.c sw_chxy.c ./libft/libft.a
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
all: $(NAME)

$(NAME): $(LIBFT)
	@gcc $(SRCS) $(FLAGS) -o $(NAME)

g:
	@gcc -g $(SRCS) -o $(NAME)

clean:
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

re: fclean all

$(LIBFT):
	$(MAKE) -C ./libft all
