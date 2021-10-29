/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:08:06 by jbyeon            #+#    #+#             */
/*   Updated: 2021/10/23 15:09:18 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    solved(t_list **astack, t_list **bstack)
{
    int     len;

    if (check_sort(*astack) != 0)
    {
        len = ft_lstsize(*astack);
        if (len == 2)
            two_sort(astack);
        else if (len == 3)
            three_sort(astack);
        else if (len < 6)
            five_sort(astack, bstack);
    }
    return ;
}
