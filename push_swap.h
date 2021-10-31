/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:22:54 by jbyeon            #+#    #+#             */
/*   Updated: 2021/06/17 16:23:48 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>

int fill_stack(t_list **astack, char **validated_data);
int validate(int argc, char **argv, t_list **astack);

int throw_error(void);

void    ft_swap(t_list **stack);
void    ft_push(t_list **from_stack, t_list **to_stack);
void    ft_rotate(t_list **stack);
void    ft_reverse_rotate(t_list **stack);

void    sa(t_list **astack);
void    sb(t_list **bstack);
void    pa(t_list **astack, t_list **bstack);
void    pb(t_list **astack, t_list **bstack);
void    ra(t_list **astack);
void    rb(t_list **bstack);
void    rra(t_list **astack);
void    rrb(t_list **bstack);


void print_stack(t_list **stack);
void rprint_stack(t_list **stack);

void    solved(t_list **astack, t_list **bstack);
void    five_sortab(t_list **astack, t_list **bstack, int size);
void    five_sortba(t_list **astack, t_list **bstack, int size);
void    five_b_to_a(t_list **astack, t_list **bstack);
void    five_a_to_b(t_list **astack, t_list **bstack);
void    three_sorta(t_list **astack);
void    three_sortb(t_list **bstack);
void    two_sorta(t_list **astack);
void    two_sortb(t_list **bstack);
int     check_sort(t_list *astack);
int     get_pivot(t_list *stack, int size);
int get_content(t_list *stack, int index);

void    a_to_b_sort(t_list **astack, t_list **bstack, int cnt);
void    b_to_a_sort(t_list **astack, t_list **bstack, int cnt);

int largest_num(t_list *stack);
int smallest_num(t_list *stack);

void    arr_free(char **str);
void    stack_free(t_list **stack);

#endif