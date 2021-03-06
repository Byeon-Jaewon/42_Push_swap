NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= ./libft/libft.a
HEADER		= push_swap.h
RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= a_op.c ab_op.c b_op.c basic_op.c error.c parse.c test.c \
			small_sort.c small_sort2.c small_sort3.c large_sort.c solve.c \
			util.c util2.c push_swap.c\
				
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