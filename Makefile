# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncosta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 16:17:55 by ncosta            #+#    #+#              #
#    Updated: 2018/06/13 14:06:08 by vsanghan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ft_first_check.c ft_second_check.c map.c validater.c \
	   main.c solver.c function_caller.c print.c


OBJ = ft_first_check.o ft_second_check.o map.o validater.o \
	  main.o solver.o function_caller.o

INC = includes/

FLAGS = -Wall -Wextra -Werror

LFT = libft/libft.a

all: $(NAME)

$(NAME) : $(SRCS) $(LFT)
	@gcc $(FLAGS) -I $(INC) $(SRCS) $(LFT) -o $(NAME)

$(LFT) :
	@make -C libft

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean
