/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:02:29 by pcorina           #+#    #+#             */
/*   Updated: 2021/12/28 19:04:55 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	shortway2(t_list **lst, long content)
{
	long	way;

	if (index_list(lst, content) <= \
	mod_num(index_list(lst, content) - num_list(lst)))
		way = index_list(lst, content);
	else
		way = index_list(lst, content) - num_list(lst);
	return (way);
}

long	shortway(t_list **lst1, t_list **lst2, long content1, long content2)
{
	long	way1;
	long	way2;

	way1 = shortway2(lst1, content1);
	way2 = shortway2(lst2, content2);
	if ((way1 < 0 && way2 < 0) || (way1 >= 0 && way2 >= 0))
		return (high_num(mod_num(way1), mod_num(way2)));
	else
		return (mod_num(way1) + mod_num(way2));
}

void	where_movenew(t_list **a, t_list **b, long numa, long numb)
{
	if (shortway2(a, numa) < 0 && shortway2(b, numb) < 0)
		where_move_rr(a, b, numa, numb);
	else if (shortway2(a, numa) >= 0 && shortway2(b, numb) >= 0)
		where_move_r(a, b, numa, numb);
	else if (shortway2(a, numa) < 0)
		where_move_rr_r(a, b, numa, numb);
	else
		where_move_r_rr(a, b, numa, numb);
}

void	who_nextnew(t_list **a, t_list **b)
{
	t_list	*lista;
	long	result;
	long	buf;
	long	numa;
	long	numb;

	result = 9223372036854775807;
	lista = *a;
	while (lista)
	{
		buf = shortway(a, b, *lista ->content, next_list(b, *lista ->content));
		if (buf < result)
		{
			result = buf;
			numa = *lista ->content;
			numb = next_list(b, *lista ->content);
		}
		lista = lista ->next;
	}
	where_movenew(a, b, numa, numb);
}

t_list	*logic(t_list *a, int argc)
{
	int		i;
	t_list	*b;

	i = -1;
	b = NULL;
	ft_move_p(&a, &b, 1);
	while (a)
		who_nextnew(&a, &b);
	if (index_list(&b, argc - 1) < (argc - 1) / 2)
		while (*b ->content != argc - 1)
			ft_move_r(&b, 2);
	else
		while (*b ->content != argc - 1)
			ft_move_rr(&b, 2);
	while (chek_finish(a, argc))
		ft_move_p(&b, &a, 2);
	return (a);
}
