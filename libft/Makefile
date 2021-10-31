# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/25 16:11:45 by jbyeon            #+#    #+#              #
#    Updated: 2021/01/06 15:42:37 by jbyeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc
CFLAGS=-Wall -Wextra -Werror
AR=ar rc
RM=rm -f

SRCS=ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	 ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c \
	 ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	 ft_memset.c ft_strrchr.c ft_strchr.c ft_strlcpy.c \
	 ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncmp.c \
	 ft_strnstr.c ft_tolower.c ft_toupper.c ft_calloc.c \
	 ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	 ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
	 ft_putendl_fd.c ft_putnbr_fd.c \
	 ft_lstnew.c ft_lstadd_front.c \
	 ft_lstsize.c ft_lstlast.c ft_lstadd_back.c


OBJS=ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o \
		ft_isascii.o ft_isdigit.o ft_isprint.o ft_memccpy.o \
		ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o \
		ft_memset.o ft_strrchr.o ft_strchr.o ft_strdup.o \
		ft_strlcpy.o ft_strlcat.o ft_strlen.o ft_strncmp.o \
		ft_strnstr.o ft_tolower.o ft_toupper.o ft_calloc.o \
		ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o \
		ft_itoa.o ft_strmapi.o ft_putchar_fd.o ft_putstr_fd.o \
		ft_putendl_fd.o ft_putnbr_fd.o \
		ft_lstnew.o ft_lstadd_front.o \
		ft_lstsize.o ft_lstlast.o ft_lstadd_back.o
all: $(NAME)

$(NAME): 
	$(CC) $(CFLAG) -c $(SRCS)
	$(AR) $(NAME) $(OBJS)

bonus:
	$(CC) $(CFLAG) -c $(SRCS_B)
	$(AR) $(NAME) $(OBJS_B)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all
