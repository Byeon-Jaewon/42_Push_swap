NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= ./libft/libft.a
HEADER		= push_swap.h
RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= a_op.c ab_op.c b_op.c basic_op.c error.c parse.c test.c push_swap.c\
				
OBJS		= $(SRCS:.c=.o)

all : $(NAME)

.c.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	$(CC) -g $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all