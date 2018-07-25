# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ftourret <ftourret@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/07/23 23:09:40 by ftourret     #+#   ##    ##    #+#        #
#    Updated: 2018/07/25 19:18:27 by ftourret    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = bsq

FLAGS = -Wall -Wextra -Werror

FILES = srcs/fcts.c srcs/main.c srcs/map_check.c srcs/map_create.c \
		srcs/map_display.c srcs/map_resolver.c

HEADER = includes/header.h

OBJ = srcs/fcts.o srcs/main.o srcs/map_check.o srcs/map_create.o \
		srcs/map_display.o srcs/map_resolver.o

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

srcs/fcts.o: srcs/fcts.c
	gcc $(FLAGS) -o srcs/fcts.o -c srcs/fcts.c -I $(HEADER)

srcs/map_display.o: srcs/map_display.c
	gcc $(FLAGS) -o srcs/map_display.o -c srcs/map_display.c -I $(HEADER)

srcs/main.o : srcs/main.c
	gcc $(FLAGS) -o srcs/main.o -c srcs/main.c -I $(HEADER)

srcs/map_check.o : srcs/map_check.c
	gcc $(FLAGS) -o srcs/map_check.o -c srcs/map_check.c -I $(HEADER)

srcs/map_create.o : srcs/map_create.c
	gcc $(FLAGS) -o srcs/map_create.o -c srcs/map_create.c -I $(HEADER)

srcs/map_resolver.o : srcs/map_resolver.c
	gcc $(FLAGS) -o srcs/map_resolver.o -c srcs/map_resolver.c -I $(HEADER)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
