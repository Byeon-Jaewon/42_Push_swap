#include "push_swap.h"

void    a_left(t_list **astack)
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

void    three_sorta(t_list **astack)
{
    if ((*astack)->content > (*astack)->next->content)
    {
        a_left(astack);
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

void    b_left(t_list **bstack)
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

void    three_sortb(t_list **bstack)
{
    if ((*bstack)->content > (*bstack)->next->content)
    {
        b_left(bstack);
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