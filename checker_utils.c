/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:34:31 by pcorina           #+#    #+#             */
/*   Updated: 2021/12/28 18:34:36 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return ((void *)0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i + j] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*buf_s1;
	unsigned char	*buf_s2;

	buf_s1 = (unsigned char *)s1;
	buf_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (buf_s1[i] == buf_s2[i] && i < n - 1 && buf_s1[i] && buf_s2[i])
		i++;
	return (buf_s1[i] - buf_s2[i]);
}
