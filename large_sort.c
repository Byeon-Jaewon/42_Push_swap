#include "push_swap.h"

void    a_reverse_rotate(t_list **astack, int ira)
{
    int i;

    i = 0;
    while (i < ira)
    {
        rra(astack);
        i++;
    }
}

void    a_b_oper(t_list **astack, t_list **bstack, int cnt, int pivot)
{
    int ira;
    int ipb;

    ira = 0;
    ipb = 0;
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
    a_reverse_rotate(astack, ira);
    a_to_b_sort(astack, bstack, ira);
    b_to_a_sort(astack, bstack, ipb);
}

void    a_to_b_sort(t_list **astack, t_list **bstack, int cnt)
{
    int pivot;

    if (cnt <= 1)
        return ;
    else if (cnt == 2)
    {
        two_sorta(astack);
        return ;
    }
    pivot = get_pivot(*astack, cnt);
    a_b_oper(astack, bstack, cnt, pivot);
}

void    b_reverse_rotate(t_list **bstack, int irb)
{
    int i;

    i = 0;
    while (i < irb)
    {
        rrb(bstack);
        i++;
    }
}

void b_a_oper(t_list **astack, t_list **bstack, int cnt, int pivot)
{
    int irb;
    int ipa;

    irb = 0;
    ipa = 0;
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
    b_reverse_rotate(bstack, irb);
    a_to_b_sort(astack, bstack, ipa);
    b_to_a_sort(astack, bstack, irb);
}

void    b_to_a_sort(t_list **astack, t_list **bstack, int cnt)
{
    int pivot;
    if (cnt <= 1)
    {
        pa(astack, bstack);
        return ;
    }
    if (cnt == 2)
    {
        two_sortb(bstack);
        pa(astack, bstack); 
        pa(astack, bstack);
        return ;
    }
    pivot = get_pivot(*bstack, cnt);
    b_a_oper(astack, bstack, cnt, pivot);
}