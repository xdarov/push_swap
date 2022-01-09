/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:39:47 by pcorina           #+#    #+#             */
/*   Updated: 2022/01/09 17:12:22 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	long	*for_free;

	if (argc > 1)
	{
		a = fill_list_start(argv, &argc);
		if (!a)
			return (0);
		for_free = a ->content;
		if (chek_finish(a, argc) && argc == 3)
			a = logic3(&a, argc);
		else if (chek_finish(a, argc) && argc == 5)
			a = logic5(&a, argc);
		else if (chek_finish(a, argc))
			a = logic(a, argc);
		free_all(&a, for_free);
	}
	return (0);
}
