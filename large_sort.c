#include "push_swap.h"

void    a_to_b_sort(t_list **astack, t_list **bstack, int cnt)
{
    int pivot;
    int ira;
    int ipb;
    int i;

    i = 0;
    ira = 0;
    ipb = 0;
    if (cnt == 1)
        return ;
    else if (cnt == 2)
    {
        two_sorta(astack);
        return ;
    }
    pivot = get_pivot(*astack, cnt);
    while (cnt > 0)
    {
        if ((*astack)->content > pivot)
        {
            ra(astack);
            ira++;
        }
        else
        {
            pb(astack, bstack);
            ipb++;
        }
        cnt--;
    }
    while (i < ira)
    {
        rra(astack);
        i++;
    }
    a_to_b_sort(astack, bstack, ira);
    b_to_a_sort(astack, bstack, ipb);
}

void    b_to_a_sort(t_list **astack, t_list **bstack, int cnt)
{
    int pivot;
    int irb;
    int ipa;
    int i;

    i = 0;
    irb = 0;
    ipa = 0;
    if (cnt == 1)
    {
        pa(astack, bstack);
        return ;
    }
    if (cnt == 2)
    {
        pa(astack, bstack);
        pa(astack, bstack);
        return ;
    }
    pivot = get_pivot(*bstack, cnt);
    while (cnt > 0)
    {
        if ((*bstack)->content < pivot)
        {
            rb(bstack);
            irb++;
        }
        else
        {
            pa(astack, bstack);
            ipa++;
        }
        cnt--;
    }
    while (i < irb)
    {
        rrb(bstack);
        i++;
    }
    b_to_a_sort(astack, bstack, irb);
    a_to_b_sort(astack, bstack, ipa);
    
}