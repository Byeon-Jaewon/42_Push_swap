/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:30:37 by jbyeon            #+#    #+#             */
/*   Updated: 2021/01/06 15:01:30 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp_n;
	t_list	*cur;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	if ((tmp = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	cur = tmp;
	lst = lst->next;
	while (lst != NULL)
	{
		if ((tmp_n = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		cur->next = tmp_n;
		cur = cur->next;
		lst = lst->next;
	}
	return (tmp);
}
