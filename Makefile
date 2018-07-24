# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nathan <nathan@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/23 23:09:40 by ftourret     #+#   ##    ##    #+#        #
#    Updated: 2018/07/24 11:57:45 by nathan      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = bsq

FLAGS = -Wall -Wextra -Werror

FILES = srcs/fcts.c srcs/main.c srcs/map_check.c srcs/map_create.c

HEADER = includes/header.h

OBJ = fcts.o main.o map_check.o map_create.o

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

fcts.o: srcs/fcts.c
	gcc $(FLAGS) -o fcts.o -c srcs/fcts.c -I $(HEADER)

main.o : srcs/main.c
	gcc $(FLAGS) -o main.o -c srcs/main.c -I $(HEADER)

map_check.o : srcs/map_check.c
	gcc $(FLAGS) -o map_check.o -c srcs/map_check.c -I $(HEADER)

map_create.o : srcs/map_create.c
	gcc $(FLAGS) -o map_create.o -c srcs/map_create.c -I $(HEADER)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
