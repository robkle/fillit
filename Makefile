# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 16:06:08 by rklein            #+#    #+#              #
#    Updated: 2019/11/22 11:30:27 by rklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILLIT_SRC = *.c

FILLIT_OBJ = *.o

INCLUDES = ./

FLAGS = -Werror -Wall -Wextra

all: $(NAME)
$(NAME):
	gcc $(FLAGS) -c $(FILLIT_SRC)
	gcc -o $(NAME) $(FLAGS) $(FILLIT_OBJ) -I $(INCLUDES) 

clean:
	rm -rf $(FILLIT_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
