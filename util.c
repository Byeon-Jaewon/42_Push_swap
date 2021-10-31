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

int get_pivot(t_list *stack, int size)
{
    t_list  *tmp_stack;
    int tmp;
    int i;

    tmp_stack = stack;
    while (size > 1)
    {
        i = 0;
        stack = tmp_stack;
        while (i < size - 1)
        {
            if (stack->content > stack->next->content)
            {
                tmp = stack->content;
                stack->content = stack->next->content;
                stack->next->content = tmp;
            }
            stack = stack->next;
            i++;
        }
        size--;
    }
    return (get_content(tmp_stack, size / 2));
}

int get_content(t_list *stack, int index)
{
    int i;

    i = 0;
    while (stack->next)
    {
        if (i == index)
            break;
        i++;
        stack = stack->next;
    }
    return (stack->content);
}