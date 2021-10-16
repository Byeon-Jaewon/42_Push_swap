/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 19:05:53 by jbyeon            #+#    #+#             */
/*   Updated: 2021/02/08 22:30:43 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		intlen(int n)
{
	int		len;

	if (n < 0)
		len = 1;
	else
		len = 0;
	if (n == 0)
		len = 1;
	else
	{
		while (n != 0)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*p;
	unsigned int	tmp;

	len = intlen(n);
	if (!(p = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	p[len--] = '\0';
	tmp = n;
	if (n == 0)
	{
		p[0] = '0';
		return (p);
	}
	if (n < 0)
	{
		tmp = n * (-1);
		p[0] = '-';
	}
	while (tmp > 0)
	{
		p[len--] = (tmp % 10) + '0';
		tmp = tmp / 10;
	}
	return (p);
}
