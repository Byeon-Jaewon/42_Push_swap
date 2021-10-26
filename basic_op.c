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

// void    ft_push(t_list **target_stack, t_list **to_stack)
// {
//     t_list  *tmp;

//     tmp = *target_stack;
//     if (*target_stack)
//     {
        
//     }
//     free(tmp);
// }

// void    ft_rotate(t_list **stack)
// {
//     t_list  *tmp;
//     t_list  *last;
    
//     if (*stack)
//     {
        
//     }
// }

// void    ft_reverse_rotate(t_list **stack)
// {
//     t_list  *tmp;
//     t_list  *last;

//     printf("check0\n");
//     if (*stack)
//     {
       
//     }
// }