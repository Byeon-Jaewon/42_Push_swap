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
    int *cp;
    int result;

    cp = copy_stack(stack, size);
    bubble_sort(cp, size);
    result = cp[size/2];
    free(cp);
    return (result);
}


int *copy_stack(t_list *stack, int size)
{
    int *cp;
    int idx;

    if (!(cp = (int *)malloc(sizeof(int) * (size - 1))))
        return (NULL);
    idx = 0;
    while (idx < size)
    {
        cp[idx] = get_content(stack, idx);
        idx ++;
    }
    return (cp);
}

int get_content(t_list *stack, int index)
{
    int i;
    int result;
    t_list *tmp;

    i = 0;
    tmp = stack;
    while (stack->next)
    {
        if (i == index)
            break;
        i++;
        stack = stack->next;
    }
    result = stack->content;
    stack = tmp;
    return (result);
}

void bubble_sort(int *arr, int size)
{
    int i;
    int j;
    int tmp;

    i = size - 1;
    while (i > 0)
    {
        j = 0;
        while (j < i)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        i--;
    }
}