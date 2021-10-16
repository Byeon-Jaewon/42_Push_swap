/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:38:57 by jbyeon            #+#    #+#             */
/*   Updated: 2021/01/05 00:09:40 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	i = 1;
	if (src_ptr < dest_ptr)
	{
		while (i <= n)
		{
			dest_ptr[n - i] = src_ptr[n - i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			*(dest_ptr++) = *(src_ptr++);
		}
	}
	return (dest);
}
