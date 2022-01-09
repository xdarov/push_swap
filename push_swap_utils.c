/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:08:53 by pcorina           #+#    #+#             */
/*   Updated: 2021/12/24 19:01:35 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	last = *lst;
	if (last == ((void *)0))
		*lst = new;
	else
	{
		while (last -> next)
			last = last -> next;
		last -> next = new;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst -> content);
		lst = lst -> next;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return ((void *)0);
	last = lst;
	while (last -> next)
	{
		last = last -> next;
	}
	return (last);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return ((void *)0);
	new -> content = content;
	new -> next = ((void *)0);
	return (new);
}

long	ft_atoi(const char *str)
{
	int			i;
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i] != '\0')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + ((str[i] - 48) * sign);
		i++;
		if (result < -2147483648 || result > 2147483647)
			return (2147483648);
	}
	return ((long)result);
}
