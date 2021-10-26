#include "push_swap.h"

void    sa(t_list **astack)
{
    ft_swap(astack);
    ft_putstr_fd("sa\n", 1);
}

// void    pa(t_list **astack, t_list **bstack)
// {
//     ft_push(bstack, astack);
//     ft_putstr_fd("pa\n", 1);
// }

// void    ra(t_list **astack)
// {
//     ft_rotate(astack);
//     ft_putstr_fd("ra\n", 1);
// }

// void    rra(t_list **astack)
// {
//     ft_swap(astack);
//     ft_swap(astack);
//     ft_putstr_fd("rra\n", 1);
// }