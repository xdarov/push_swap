/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_logic2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:13:07 by pcorina           #+#    #+#             */
/*   Updated: 2021/12/24 15:15:43 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	next_list(t_list **lst, long num)
{
	long	result;
	long	max;
	t_list	*list;

	list = *lst;
	result = -2147483649;
	max = -2147483649;
	while (list)
	{
		if (*list ->content > max)
			max = *list ->content;
		if (num > *list ->content && *list ->content > result)
			result = *list ->content;
		list = list ->next;
	}
	if (result == -2147483649)
		return (max);
	return (result);
}

void	where_move_rr(t_list **a, t_list **b, long numa, long numb)
{
	t_list	*lista;
	t_list	*listb;

	lista = *a;
	listb = *b;
	while (*listb ->content != numa)
	{
		if (*lista ->content != numa && *listb ->content != numb)
		{
			ft_move_rr(a, 0);
			ft_move_rr(b, 3);
		}
		else if (*lista ->content == numa && *listb ->content != numb)
			ft_move_rr(b, 2);
		else if (*lista ->content != numa && *listb ->content == numb)
			ft_move_rr(a, 1);
		else if (*lista ->content == numa && *listb ->content == numb)
			ft_move_p(a, b, 1);
		lista = *a;
		listb = *b;
	}
}

void	where_move_r(t_list **a, t_list **b, long numa, long numb)
{
	t_list	*lista;
	t_list	*listb;

	lista = *a;
	listb = *b;
	while (*listb ->content != numa)
	{
		if (*lista ->content != numa && *listb ->content != numb)
		{
			ft_move_r(a, 0);
			ft_move_r(b, 3);
		}
		else if (*lista ->content == numa && *listb ->content != numb)
			ft_move_r(b, 2);
		else if (*lista ->content != numa && *listb ->content == numb)
			ft_move_r(a, 1);
		else if (*lista ->content == numa && *listb ->content == numb)
			ft_move_p(a, b, 1);
		lista = *a;
		listb = *b;
	}
}

void	where_move_rr_r(t_list **a, t_list **b, long numa, long numb)
{
	t_list	*lista;
	t_list	*listb;

	lista = *a;
	listb = *b;
	while (*lista ->content != numa || (listb && *listb ->content != numb))
	{
		if (*lista ->content != numa)
			ft_move_rr(a, 1);
		if (listb && *listb ->content != numb)
			ft_move_r(b, 2);
		lista = *a;
		listb = *b;
	}
	ft_move_p(a, b, 1);
}

void	where_move_r_rr(t_list **a, t_list **b, long numa, long numb)
{
	t_list	*lista;
	t_list	*listb;

	lista = *a;
	listb = *b;
	while (*lista ->content != numa || (listb && *listb ->content != numb))
	{
		if (*lista ->content != numa)
			ft_move_r(a, 1);
		if (listb && *listb ->content != numb)
			ft_move_rr(b, 2);
		lista = *a;
		listb = *b;
	}
	ft_move_p(a, b, 1);
}
