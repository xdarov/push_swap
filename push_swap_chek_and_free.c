/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chek_and_free.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:42:55 by pcorina           #+#    #+#             */
/*   Updated: 2022/01/09 17:31:40 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chek_int(long *arr, int argc)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc)
	{
		if (arr[i] < -2147483648 || arr[i] > 2147483647)
		{
			free(arr);
			return (write(2, "Error\n", 6));
		}
		j = 1;
		while (j + i < argc)
		{
			if (arr[i] == arr[i + j])
			{
				free(arr);
				return (write(2, "Error\n", 6));
			}
			j++;
		}
	}
	return (0);
}

void	free_all(t_list **a, long *for_free)
{
	t_list	*list;
	t_list	*freelist;

	list = *a;
	free(for_free);
	while (list)
	{
		freelist = list;
		list = list ->next;
		free(freelist);
	}
}

int	chek(char **argv, int argc, int i)
{
	int	j;

	while (++i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] || argv[i][j - 1] == '-')
		{
			if (!ft_isdigit(argv[i][j]))
				return (write(2, "Error\n", 6));
			j++;
		}
	}
	return (0);
}

int	arrlen_or_free(char **argv, int j)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!j)
			free(argv[i]);
		i++;
	}
	if (!j)
	{
		free(argv[i]);
		free(argv);
	}
	return (i);
}
