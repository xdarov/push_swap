/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:08:43 by pcorina           #+#    #+#             */
/*   Updated: 2021/12/28 21:09:57 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	long			*content;
	struct s_list	*next;
}	t_list;

int		arrlen_or_free(char **argv, int j);
int		chek(char **argv, int argc, int i);
void	free_all(t_list **a, long *for_free);
int		chek_int(long *arr, int argc);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int ch);
void	where_move_rr_r(t_list **a, t_list **b, long numa, long numb);
void	where_move_r(t_list **a, t_list **b, long numa, long numb);
void	where_move_rr(t_list **a, t_list **b, long numa, long numb);
void	where_move_r_rr(t_list **a, t_list **b, long numa, long numb);
long	shortway2(t_list **lst, long content);
long	next_list(t_list **lst, long num);
long	mod_num(long l);
int		index_list(t_list **lst, long content);
long	high_num(long a, long b);
int		num_list(t_list **lst);
void	show(t_list *list, char *lst);
int		main(int argc, char **argv);
long	ft_atoi(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_move_s(t_list **lst, int output);
void	ft_move_p(t_list **lst1, t_list **lst2, int output);
void	ft_move_r(t_list **lst, int output);
void	ft_move_rr(t_list **lst, int output);
int		chek_finish(t_list *lst, int argc);
t_list	*fill_list_start(char **argv, int *argc);
long	*index_arr(long *arr, int argc);
t_list	*fill_list(char **argv, int argc);
t_list	*fill_list2(char **argv, int argc);
t_list	*logic(t_list *a, int argc);
t_list	*logic3(t_list **a, int argc);
t_list	*logic5(t_list **a, int argc);
int		main(int argc, char **argv);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin_free(char *s1, char *s2);
size_t	ft_strlen(const char *s);

#endif
