/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsort.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 15:57:13 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 15:57:16 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	get_lesser(const t_list *lst,
		int (*f)(void *, size_t, void *, size_t))
{
	size_t			index_min;
	size_t			i;
	const t_list	*mini;

	i = 0;
	index_min = 0;
	mini = lst;
	while (lst)
	{
		if (f(mini->content, mini->content_size, lst->content,
					lst->content_size))
		{
			index_min = i;
			mini = lst;
		}
		lst = lst->next;
		++i;
	}
	return (index_min);
}

void		ft_lstsort(t_list **lst, int (*f)(void *, size_t, void *, size_t))
{
	t_list *mini;
	t_list *first;
	t_list *tmp;
	size_t index_min;
	size_t i;

	i = 0;
	first = *lst;
	while (first)
	{
		index_min = get_lesser(first, f);
		if (index_min != 0)
		{
			mini = ft_lstat(first, index_min - 1);
			tmp = mini->next;
			mini->next = mini->next->next;
			ft_lstins(lst, tmp, i);
		}
		else
			first = first->next;
		++i;
	}
}
