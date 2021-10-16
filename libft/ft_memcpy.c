/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:17:10 by jbyeon            #+#    #+#             */
/*   Updated: 2021/01/04 23:33:17 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*tmp;
	unsigned char			*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	tmp = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (n > 0)
	{
		*tmp = *s;
		tmp++;
		s++;
		n--;
	}
	return (dest);
}
