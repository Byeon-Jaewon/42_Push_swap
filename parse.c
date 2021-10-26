/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:36:34 by jbyeon            #+#    #+#             */
/*   Updated: 2021/10/24 13:49:12 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_input_int(char **str)
{
    int     i;
    int     j;
    int     size;

    i = 0;
    while (str[i])
    {
        j = 0;
        size = ft_strlen(str[i]);
        while (str[i][j])
        {
            if (ft_isdigit(str[i][j]) != 1 && str[i][j] != '-' && str[i][j] != '+')
                return throw_error();
            if ((str[i][j] == '-' || str[i][j] =='+') && j == size - 1)
                return throw_error();
            j++;
        }
        i++;
    }
    return (0);
}

int duplicates(t_list *stack, int num)
{
    while (stack)
    {
        if (stack->content == num)
            return throw_error();
        stack = stack->next;
    }
    return (0);
}

int fill_stack(t_list **astack, char **validated_data)
{
    int     num;
    int     j;
    int     i;
    t_list  *tmp;
    
    tmp = NULL;
    j = 0;
    while (validated_data[j])
        j++;
    i = j - 1;
    while (i != -1)
    {
        num = ft_atoi(validated_data[i]);
        if (duplicates(*astack, num) == 1)
            return throw_error();
        tmp = ft_lstnew(num);
        ft_lstadd_back(astack, tmp);
        i--;
    }
    return (0);
}

int validate(int argc, char **argv, t_list **astack)
{
    int     i;
    char    **validated_data;

    i = argc - 1;
    while (i != 0)
    {
        validated_data = ft_split(argv[i], ' ');
        if (check_input_int(validated_data) == 1)
            return throw_error();
        if(!validated_data)
            return throw_error();
        if (fill_stack(astack, validated_data) == 1)
            return throw_error();
        arr_free(validated_data);
        i--;
    }
    return (0);
}
