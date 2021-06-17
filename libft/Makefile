# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 15:36:18 by jbyeon            #+#    #+#              #
#    Updated: 2021/06/17 16:19:29 by jbyeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR=ar rc
RM=rm -f

SRCS = ft_lstnew.c ft_lstpush.c

OBJS = ft_lstnew.o ft_lstpush.o

all : $(NAME)

$(NAME) :
		$(CC) $(CFLAG) -c $(SRCS)
		$(AR) $(NAME) $(OBJS)

clean : 
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all