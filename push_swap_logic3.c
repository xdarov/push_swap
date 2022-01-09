/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_logic3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:35:40 by pcorina           #+#    #+#             */
/*   Updated: 2021/12/24 18:35:47 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*logic3(t_list **a, int argc)
{
	t_list	*lista;

	lista = *a;
	if (*lista ->next->next->content == argc - 1)
		ft_move_rr(a, 1);
	lista = *a;
	while (!(*lista ->next->next->content > *lista ->next->content \
			&& *lista ->next->content > *lista ->content))
	{
		if (*lista ->next->next->content != argc - 1)
			ft_move_r(a, 1);
		else
			ft_move_s(a, 1);
		lista = *a;
	}
	return (lista);
}

t_list	*logic5(t_list **a, int argc)
{
	t_list	*lista;
	t_list	*listb;

	lista = *a;
	listb = NULL;
	if (shortway2(a, 0) < 0)
		where_move_rr_r(a, &listb, 0, 0);
	else
		where_move_r_rr(a, &listb, 0, 0);
	lista = *a;
	if (shortway2(a, 1) < 0)
		where_move_rr_r(a, &listb, 1, 0);
	else
		where_move_r_rr(a, &listb, 1, 0);
	lista = *a;
	lista = logic3(&lista, argc);
	ft_move_p(&lista, &listb, 2);
	ft_move_p(&lista, &listb, 2);
	return (lista);
}
