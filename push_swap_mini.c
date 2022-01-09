/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mini.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:13:03 by pcorina           #+#    #+#             */
/*   Updated: 2021/12/28 18:48:09 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	high_num(long a, long b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	num_list(t_list **lst)
{
	int		i;
	t_list	*list;

	list = *lst;
	i = 0;
	while (list)
	{
		list = list ->next;
		i++;
	}
	return (i);
}

int	index_list(t_list **lst, long content)
{
	int		i;
	t_list	*list;

	list = *lst;
	i = 0;
	while (list && *list ->content != content)
	{
		list = list ->next;
		i++;
	}
	return (i);
}

long	mod_num(long l)
{
	if (l < 0)
		return (-l);
	else
		return (l);
}

int	ft_isdigit(int ch)
{
	if (ch >= 48 && ch <= 57)
		return (1);
	return (0);
}
