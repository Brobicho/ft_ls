/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 15:45:06 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 17:52:11 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"
#include <stdlib.h>

void		remove_last(t_file **begin, int count)
{
	int		i;
	t_file	*tmp;
	t_file	*old;

	i = 0;
	tmp = *begin;
	old = *begin;
	while (i != count - 1)
	{
		tmp = tmp->next;
		i = i + 1;
	}
	tmp->next = 0;
	*begin = old;
}

int		ft_rev_list(t_file **begin)
{
	t_file	*tmp;
	t_file	*tmp_next;
	t_file	*rev;
	int		count;

	count = 0;
	rev = *begin;
	while (rev != '\0')
	{
		if (tmp->next == tmp)
			tmp->next->next = 0;
		tmp_next = rev->next;
		rev->next = tmp;
		tmp = rev;
		rev = tmp_next;
		count = count + 1;
	}
	*begin = tmp;
	remove_last(begin, count);
	return (0);
}

t_file		*next_list(t_file *list, struct dirent *dir)
{
	t_file	*new;

	new =  malloc(sizeof(*new));
	if (new == '\0')
		return (0);
	new->dir = dir;
	new->next = list;
	return (new);
}

void		ft_sort_list(t_file **list, int r)
{
	if (r == 1)
		ft_rev_list(list);
}
