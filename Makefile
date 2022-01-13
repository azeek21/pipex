# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malton <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 15:12:39 by malton            #+#    #+#              #
#    Updated: 2022/01/07 00:32:27 by malton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = clang

CFLAGS = -Wall -Wextra -Werror

HEADER = pipex.h

SRC = ft_family.c\
	ft_get_path.c\
	ft_path_parser_tools.c\
	ft_path_parser.c\
	ft_split.c\
	functions.c\
	functions_1.c\
	functions_2.c\
	ft_cmd_checker.c\
	pipex.c


OBJ = $(SRC:.c=.o)

BON_SRC = *.c

BON_OBJ = $(BON_SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -g3 -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -g3 -c $< 

bonus: $(BON_OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(BON_OBJ)

clean:
		rm -f $(OBJ) $(BON_OBJ)
	
fclean: clean
		rm -f $(NAME)

re: fclean all

