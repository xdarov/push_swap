/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:08:57 by pcorina           #+#    #+#             */
/*   Updated: 2022/01/09 17:14:49 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*index_arr(long *arr, int argc)
{
	int		i;
	int		j;
	long	min;
	long	next;

	next = -1;
	while (++next < argc)
	{
		i = -1;
		min = 2147483648;
		while (++i < argc)
		{
			if (arr[i] < min)
			{
				min = arr[i];
				j = i;
			}
		}
		arr[j] = 9223372036854775807 - next;
	}
	i = -1;
	while (++i < argc)
		arr[i] = (arr[i] - 9223372036854775807) * -1;
	return (arr);
}

t_list	*fill_list(char **argv, int argc)
{
	t_list		*list;
	int			i;
	long		*arr;

	arr = (long *)malloc(sizeof(long) * argc);
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < argc)
		arr[i] = ft_atoi(argv[i + 1]);
	if (chek_int(arr, argc))
		return (NULL);
	arr = index_arr(arr, argc);
	list = ft_lstnew(&arr[0]);
	i = 0;
	while (++i < argc)
		ft_lstadd_back(&list, ft_lstnew(&arr[i]));
	return (list);
}

t_list	*fill_list2(char **argv, int argc)
{
	t_list		*list;
	int			i;
	long		*arr;

	arr = (long *)malloc(sizeof(long) * argc);
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < argc)
		arr[i] = ft_atoi(argv[i]);
	if (chek_int(arr, argc))
		return (NULL);
	arrlen_or_free(argv, 0);
	arr = index_arr(arr, argc);
	list = ft_lstnew(&arr[0]);
	i = 0;
	while (++i < argc)
		ft_lstadd_back(&list, ft_lstnew(&arr[i]));
	return (list);
}

t_list	*fill_list_start(char **argv, int *argc)
{	
	t_list	*a;

	if (*argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		*argc = arrlen_or_free(argv, 1);
		if (chek(argv, *argc, -1))
			return (NULL);
		a = fill_list2(argv, *argc);
	}
	else
	{
		if (chek(argv, *argc, 0))
			return (NULL);
		a = fill_list(argv, --(*argc));
	}
	return (a);
}
