#include "push_swap.h"
#include <stdio.h>

void	printstack(t_list *stack)
{
	while (stack->next != NULL)
	{
		printf("%d", stack->content);
		stack = stack->next;
	}
	printf("%d", stack->content);
}
int     main(void)
{
	t_list *stack;

	stack = ft_lstnew(3);
	ft_lstpush(stack, 5);
	ft_lstpush(stack, 2);
	ft_lstpush(stack, 7);
	printstack(stack);
}