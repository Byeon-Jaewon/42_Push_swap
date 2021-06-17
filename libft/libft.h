/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:29:24 by jbyeon            #+#    #+#             */
/*   Updated: 2021/06/17 15:33:39 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct      s_list
{
    int                num;
    struct s_list      *next;
}                   t_list;

t_list              *ft_lstnew(int num);
void	            ft_lstpush(t_list *stack, int n);

#endif