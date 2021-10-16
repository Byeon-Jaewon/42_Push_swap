/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:24:07 by jbyeon            #+#    #+#             */
/*   Updated: 2021/01/03 16:45:41 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_c;
	t_list	*tmp_n;

	tmp_c = *lst;
	while (tmp_c != NULL)
	{
		tmp_n = tmp_c->next;
		ft_lstdelone(tmp_c, del);
		tmp_c = tmp_n;
	}
	*lst = NULL;
}
