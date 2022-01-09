/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:54:54 by pcorina           #+#    #+#             */
/*   Updated: 2021/12/28 20:29:55 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*input(void)
{
	int		ret;
	char	*buf;
	char	*str;

	ret = 1;
	buf = (char *)malloc(2);
	if (!buf)
		return (NULL);
	*buf = 1;
	str = (char *)malloc(2);
	if (!str)
		return (NULL);
	while (ret > 0 && *buf != '\n')
	{
			ret = (read(0, buf, 1));
			buf[ret] = '\0';
			str = ft_strjoin_free(str, buf);
	}
	free(buf);
	return (str);
}

char	app_spr(char *command, t_list **a, t_list **b)
{
	if (!ft_strncmp(command, "sa\n", 3))
		ft_move_s(a, 0);
	else if (!ft_strncmp(command, "sb\n", 3))
		ft_move_s(b, 0);
	else if (!ft_strncmp(command, "pa\n", 3))
		ft_move_p(b, a, 0);
	else if (!ft_strncmp(command, "pb\n", 3))
		ft_move_p(a, b, 0);
	else if (!ft_strncmp(command, "ra\n", 3))
		ft_move_r(a, 0);
	else if (!ft_strncmp(command, "rb\n", 3))
		ft_move_r(b, 0);
	else
		return (write (2, "Error\n", 6));
	return (0);
}

char	app_rr(char *command, t_list **a, t_list **b)
{
	if (!ft_strncmp(command, "rra\n", 4))
		ft_move_rr(a, 0);
	else if (!ft_strncmp(command, "rrb\n", 4))
		ft_move_rr(b, 0);
	else if (!ft_strncmp(command, "rrr\n", 4))
	{
		ft_move_rr(a, 0);
		ft_move_rr(b, 0);
	}
	else if (!ft_strncmp(command, "rr\n", 3))
	{
		ft_move_r(a, 0);
		ft_move_r(b, 0);
	}
	else
		return (write (2, "Error\n", 6));
	return (0);
}

t_list	*app_command(t_list **a, t_list **b, int argc)
{
	char	*command;

	command = input();
	while (command && *command)
	{
		if (!ft_strncmp(command, "rr", 2))
		{
			if (app_rr(command, a, b))
				break ;
		}
		else
			if (app_spr(command, a, b))
				break ;
		free(command);
		command = input();
	}
	if (!command)
		return (*a);
	if (!chek_finish(*a, argc) && !*command)
		write (1, "OK\n", 3);
	else if (!*command)
		write (1, "KO\n", 3);
	free(command);
	return (*a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	long	*for_free;

	if (argc > 1)
	{
		b = NULL;
		a = fill_list_start(argv, &argc);
		if (!a)
			return (0);
		for_free = a ->content;
		a = app_command(&a, &b, argc);
		free_all(&a, for_free);
	}
	return (0);
}
