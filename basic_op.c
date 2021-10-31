#include "push_swap.h"

void    ft_swap(t_list **stack)
{
    int     tmp;

    tmp = 0;
    if ((*stack) && (*stack)->next)
    {
        tmp = (*stack)->content;
        (*stack)->content = (*stack)->next->content;
        (*stack)->next->content = tmp;
    }
}

void    ft_push(t_list **target_stack, t_list **to_stack)
{
    t_list  *tmp;

    tmp = (*target_stack);
    if (*target_stack)
    {
        (*target_stack) = (*target_stack)->next;
        if (!(*to_stack))
        {
            tmp->next = NULL;
            tmp->prev = NULL;
            (*to_stack) = tmp;
        }
        else 
        {
            tmp->next = (*to_stack);
            tmp->prev = NULL;
            (*to_stack)->prev = tmp;
            (*to_stack) = (*to_stack)->prev;
        }
    }
}

void    ft_rotate(t_list **stack)
{
    t_list  *tmp;
    t_list  *last;
    
    if ((*stack)->next)
    {
        tmp = (*stack);
        last = ft_lstlast(*stack);
        (*stack) = (*stack)->next;
        tmp->next = NULL;
        tmp->prev = last;
        last->next = tmp;
    }
}

void    ft_reverse_rotate(t_list **stack)
{
    t_list  *last;

    if ((*stack)->next)
    {
       last = ft_lstlast(*stack);
       last->prev->next = NULL;
       last->prev = NULL;
       last->next = (*stack);
       (*stack)->prev = last;
       (*stack) = last;
    }
}