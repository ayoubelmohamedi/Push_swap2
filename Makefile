# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asodor <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 10:33:52 by asodor            #+#    #+#              #
#    Updated: 2024/08/21 10:34:01 by asodor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARCHIVE = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra 

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $< -o $@

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 
	
clean :
	rm -f $(OBJS) 

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclea re
