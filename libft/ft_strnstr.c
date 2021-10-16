/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:09:54 by jbyeon            #+#    #+#             */
/*   Updated: 2020/12/25 16:26:32 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	index = 0;
	while (big[index] != '\0' && index < len)
	{
		if (big[index] == little[0])
		{
			i = 1;
			while (little[i] != '\0' && big[index + i] == little[i]
					&& (index + i) < len)
			{
				i++;
			}
			if (little[i] == '\0')
				return ((char *)&big[index]);
		}
		index++;
	}
	return (NULL);
}
