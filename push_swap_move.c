/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:50:41 by pcorina           #+#    #+#             */
/*   Updated: 2021/12/28 20:17:51 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_s(t_list **lst, int output)
{
	t_list	*list;
	t_list	*list2;

	list = *lst;
	if (!*lst || !list ->next)
		return ;
	list2 = list ->next;
	list ->next = list2 ->next;
	list2 ->next = list;
	*lst = list2;
	if (output == 1)
		write(1, "sa\n", 3);
	else if (output == 2)
		write(1, "sb\n", 3);
}

void	ft_move_p(t_list **lst1, t_list **lst2, int output)
{
	t_list	*list1;
	t_list	*list2;

	if (!*lst1)
		return ;
	if (!*lst2)
	{
		list1 = *lst1;
		*lst2 = list1;
		*lst1 = list1 ->next;
		list1 ->next = NULL;
	}
	else
	{
		list1 = *lst1;
		list2 = *lst2;
		*lst1 = list1 ->next;
		*lst2 = list1;
		list1 ->next = list2;
	}
	if (output == 1)
		write(1, "pb\n", 3);
	else if (output == 2)
		write(1, "pa\n", 3);
}

void	ft_move_r(t_list **lst, int output)
{
	t_list	*list;

	list = *lst;
	if (!*lst || !list ->next)
		return ;
	*lst = list ->next;
	list ->next = NULL;
	ft_lstadd_back(lst, list);
	if (output == 1)
		write(1, "ra\n", 3);
	else if (output == 2)
		write(1, "rb\n", 3);
	else if (output == 3)
		write(1, "rr\n", 3);
}

void	ft_move_rr(t_list **lst, int output)
{
	t_list	*list_last;
	t_list	*list;

	list = *lst;
	if (!*lst || !list ->next)
		return ;
	list_last = ft_lstlast(list);
	list_last ->next = list;
	*lst = list_last;
	while (list ->next != list_last)
		list = list ->next;
	list->next = NULL;
	if (output == 1)
		write(1, "rra\n", 4);
	else if (output == 2)
		write(1, "rrb\n", 4);
	else if (output == 3)
		write(1, "rrr\n", 4);
}

int	chek_finish(t_list *lst, int argc)
{
	int	i;

	i = -1;
	while (lst && ++i == (int)*lst ->content)
		lst = lst->next;
	if (i + 1 == argc)
		return (0);
	return (1);
}
