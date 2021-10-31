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