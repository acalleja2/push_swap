# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acalleja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/20 16:19:45 by acalleja          #+#    #+#              #
#    Updated: 2018/01/13 02:38:51 by acalleja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME2 = push_swap

NAME3 = visu

SRC = checker.c\
	  create.c\
	  error.c\
	  action.c\
	  action2.c\
	  index.c\

SRC2 = push_swap.c\
	   create.c\
	   error.c\
	   action_p.c\
	   action_p2.c\
	   index_p.c\
	   check.c\
	   cpy.c\
	   check2.c\
	   print.c\
	   select.c\
	   select2.c\
	   action_test.c\
	   quick1.c\
	   quick2.c\
	   medium.c\
	   pars.c\


SRC3 = visu.c\
	   print_elem.c\
	   put_background.c\
	   create.c\
	   error.c\
	   action.c\
	   act2.c\
	   lst.c\
	   check.c\
	   cpy.c\
	   check2.c\
	   min.c\
	   rang.c\
	   len.c\
	   pars.c\

OBJ:=$(SRC:.c=.o)

OBJ2:=$(SRC2:.c=.o)

OBJ3:=$(SRC3:.c=.o)

all : $(NAME) $(NAME2) $(NAME3)

$(NAME) : $(SRC) $(SRC2) $(SRC3)
	make -C libft/
	gcc -Wall -Werror -Wextra -c $(SRC) -I push_swap.h
	gcc -Wall -Werror -Wextra -c $(SRC2) -I push_swap.h
	gcc -Wall -Werror -Wextra -c $(SRC3) -I push_swap.h 
	gcc -o $(NAME) $(OBJ) libft/libft.a
	gcc -o $(NAME2) $(OBJ2) libft/libft.a
	gcc -o $(NAME3) $(OBJ3) libft/libft.a -lmlx -framework OpenGL -framework AppKit


clean: 
	rm -rf $(OBJ)
	rm -rf $(OBJ2)
	rm -rf $(OBJ3)
	make -C libft/ clean

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME2)
	rm -rf $(NAME3)
	make -C libft/ fclean

re : fclean all
