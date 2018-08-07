/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 17:46:50 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 15:45:41 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free_entry(t_entry *entry)
{
	free(entry->n_f);
	free(entry->p_nf);
	free(entry);
}

void	ft_lstfree(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_free_entry(tmp->content);
		tmp = tmp->next;
	}
	tmp = lst;
	while (tmp)
	{
		lst = tmp;
		tmp = tmp->next;
		free(lst);
	}
}
