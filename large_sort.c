#include "push_swap.h"

void    a_to_b_sort(t_list **astack, t_list **bstack, int cnt)
{
    int pivot;
    int ira;
    int ipb;
    int i;
    int idx;

    i = 0;
    ira = 0;
    ipb = 0;
    if (cnt <= 1)
        return ;
    else if (cnt == 2)
    {
        two_sorta(astack);
        return ;
    }
    idx = cnt;
    // print_stack(astack);
    // print_stack(bstack);
    // pivot = get_pivot(*astack, cnt);
    pivot = (*astack)->content;
    // printf("pivot : %d\n", pivot);
    while (idx > 0)
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
        idx--;
    }
    // printf("ra: %d, pb : %d\n", ira, ipb);
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
    int idx;

    i = 0;
    irb = 0;
    ipa = 0;
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
    idx = cnt;
    // print_stack(astack);
    // print_stack(bstack);
    pivot = (*bstack)->content;
    // printf("pivot : %d\n", pivot);
    while (idx > 0)
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
        idx--;
    }
    // printf("rb: %d, pa : %d\n", irb, ipa);
    while (i < irb)
    {
        rrb(bstack);
        i++;
    }
    a_to_b_sort(astack, bstack, ipa);
    b_to_a_sort(astack, bstack, irb);
}