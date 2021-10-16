/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 21:44:49 by jbyeon            #+#    #+#             */
/*   Updated: 2021/01/06 17:25:15 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_word(char const *s, char c)
{
	size_t	wc;
	int		i;
	int		flag;

	i = 0;
	wc = 0;
	flag = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (flag == 0 && s[i] != c)
		{
			flag = 1;
			wc++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (wc);
}

int		chk_next(char const *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while (ptr[i] != c)
	{
		if (ptr[i] == '\0')
			return (ft_strlen(ptr) + 1);
		i++;
	}
	return (i + 1);
}

char	*skip_c(char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	int		i;
	size_t	offset;
	char	**p;
	char	*p1;

	wc = count_word(s, c);
	if (!(p = (char **)malloc(sizeof(char *) * (wc + 1))))
		return (NULL);
	i = 0;
	offset = 0;
	p1 = (char *)s;
	p1 = skip_c(p1, c);
	while (i < wc)
	{
		offset = (size_t)chk_next(p1, c);
		if (!(p[i] = (char *)malloc(sizeof(char) * offset)))
			return (NULL);
		ft_strlcpy(p[i], p1, offset);
		p1 = p1 + offset;
		p1 = skip_c(p1, c);
		i++;
	}
	p[i] = NULL;
	return (p);
}
