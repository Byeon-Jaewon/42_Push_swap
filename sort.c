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

void    two_sort(t_list **astack)
{
    printf("two sort start!\n");
    if ((*astack)->content > (*astack)->next->content)
        sa(astack);
}

void    three_sort(t_list **astack)
{
    printf("three sort start!\n");
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

void    five_sort(t_list **astack, t_list **bstack)
{
    int     max;
    int     min;
    int     size;

    max = largest_num(*astack);
    min = smallest_num(*astack);
    size = ft_lstsize(*astack);
    printf("five sort start!\n");
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
        two_sort(astack);
    else if (size == 3)
        three_sort(astack);
    five_b_to_a(astack, bstack);
}

void    five_b_to_a(t_list **astack, t_list **bstack)
{
    printf("b to a\n");
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