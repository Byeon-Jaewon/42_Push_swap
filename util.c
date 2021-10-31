#include "push_swap.h"

int largest_num(t_list *stack)
{
    int     large;

    large = (stack)->content;
    (stack) = (stack)->next;
    while (stack)
    {
        if (stack->content > large)
            large = stack->content;
        (stack) = (stack)->next;
    }
    return (large);
}

int smallest_num(t_list *stack)
{
    int     small;

    small = (stack)->content;
    (stack) = (stack)->next;
    while (stack)
    {
        if (stack->content < small)
            small = stack->content;
        (stack) = (stack)->next;
    }
    return (small);
}