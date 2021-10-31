#include "push_swap.h"

int     check_sort(t_list *astack)
{

    while ((astack)->next)
    {
        if ((astack)->content > (astack)->next->content)
            return (1);
        astack = (astack)->next;
    }
    return (0);
}

void    two_sorta(t_list **astack)
{
    if ((*astack)->content > (*astack)->next->content)
        sa(astack);
}

void    two_sortb(t_list **bstack)
{
    if ((*bstack)->content < (*bstack)->next->content)
        sb(bstack);
}

void    three_sorta(t_list **astack)
{
    if ((*astack)->content > (*astack)->next->content)
    {
        if ((*astack)->next->next->content > (*astack)->next->content)
        {
            if ((*astack)->content > (*astack)->next->next->content)
                return ra(astack);
            return sa(astack);
        }
        else
        {
            sa(astack);
            rra(astack);
        }
    }
    else
    {
        if ((*astack)->content > (*astack)->next->next->content)
            return rra(astack);
        else if ((*astack)->next->content > (*astack)->next->next->content)
        {
            sa(astack);
            ra(astack);
        }
    }
}

void    three_sortb(t_list **bstack)
{
    if ((*bstack)->content > (*bstack)->next->content)
    {
        if ((*bstack)->next->next->content > (*bstack)->next->content)
        {
            if ((*bstack)->content > (*bstack)->next->next->content)
                return rb(bstack);
            return sb(bstack);
        }
        else
        {
            sb(bstack);
            rrb(bstack);
        }
    }
    else
    {
        if ((*bstack)->content > (*bstack)->next->next->content)
            return rrb(bstack);
        else if ((*bstack)->next->content > (*bstack)->next->next->content)
        {
            sb(bstack);
            rb(bstack);
        }
    }
}

void    five_sortab(t_list **astack, t_list **bstack, int size)
{
    int     max;
    int     min;

    max = largest_num(*astack);
    min = smallest_num(*astack);
    // size = ft_lstsize(*astack);
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
    // size = ft_lstsize(*bstack);
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