#include "push_swap.h"

void    sb(t_list **bstack)
{
    ft_swap(bstack);
    ft_putstr_fd("sb\n", 1);
}

void    pb(t_list **astack, t_list **bstack)
{
    ft_push(astack, bstack);
    ft_putstr_fd("pb\n", 1);
}

void    rb(t_list **bstack)
{
    ft_rotate(bstack);
    ft_putstr_fd("rb\n", 1);
}

void    rrb(t_list **bstack)
{
    ft_swap(bstack);
    ft_swap(bstack);
    ft_putstr_fd("rrb\n", 1);
}