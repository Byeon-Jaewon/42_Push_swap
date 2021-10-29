/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:39:43 by jbyeon            #+#    #+#             */
/*   Updated: 2021/10/23 14:38:48 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_list  *astack;
    t_list  *bstack;

    astack = NULL;
    bstack = NULL;
    if (argc > 1 && (validate(argc, argv, &astack) != 0))
    {
        stack_free(&astack);
        return throw_error();
    }
    print_stack(&astack);
    solved(&astack, &bstack);
    print_stack(&astack);
    print_stack(&bstack);
    stack_free(&astack);
    // stack_free(&bstack);

    
    return (0);
}
