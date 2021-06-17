/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:33:48 by jbyeon            #+#    #+#             */
/*   Updated: 2021/06/17 16:14:16 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list *stack, int n)
{
	t_list	*new;
	new = ft_lstnew(n);
	while (stack->next != NULL)
		stack = stack->next;
	if (stack->next == NULL)
		stack->next = new;
}