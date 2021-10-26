#include "push_swap.h"
#include <stdio.h>

void print_stack(t_list **stack)
{
    t_list *tmp;

    if (!(*stack))
    {
        return ;
    }
    printf("stack print start ! \n");
    tmp = (*stack);
    while ((*stack))
    {
        printf("%d->", (*stack)->content);
        (*stack) = (*stack)->next;
    }
    (*stack) = tmp;
    printf("\n");
}

void    arr_free(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i++]);
    }
}