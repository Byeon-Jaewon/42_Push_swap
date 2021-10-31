#include "push_swap.h"

void    five_sortab(t_list **astack, t_list **bstack, int size)
{
    int     max;
    int     min;

    max = largest_num(*astack);
    min = smallest_num(*astack);
    while (size != 0)
    {
        if ((*astack)->content == max || (*astack)->content == min)
            pb(astack, bstack);
        else
            ra(astack);
        size--;
    }
    size = ft_lstsize(*astack);
    if (size == 2)
        two_sorta(astack);
    else if (size == 3)
        three_sorta(astack);
    five_b_to_a(astack, bstack);
}

void    five_sortba(t_list **astack, t_list **bstack, int size)
{
    int     max;
    int     min;

    max = largest_num(*bstack);
    min = smallest_num(*bstack);
    while (size != 0)
    {
        if ((*bstack)->content == max || (*bstack)->content == min)
            pa(astack, bstack);
        else
            rb(bstack);
        size--;
    }
    size = ft_lstsize(*bstack);
    if (size == 2)
        two_sortb(bstack);
    else if (size == 3)
        three_sortb(bstack);
    five_a_to_b(astack, bstack);
}

void    five_b_to_a(t_list **astack, t_list **bstack)
{
    while (*bstack)
    {
        if ((*astack)->content > (*bstack)->content)
            pa(astack, bstack);
        else
        {
            pa(astack, bstack);
            ra(astack);
        }
    }
}

void    five_a_to_b(t_list **astack, t_list **bstack)
{
    while (*astack)
    {
        if ((*bstack)->content > (*astack)->content)
            pb(astack, bstack);
        else
        {
            pb(astack, bstack);
            rb(astack);
        }
    }
}