/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstins.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 15:55:10 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 15:55:14 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstins(t_list **lst, t_list *new, size_t index)
{
	t_list *insert;
	t_list *tmp;

	if (index == 0)
	{
		tmp = *lst;
		*lst = new;
		(*lst)->next = tmp;
	}
	else
	{
		insert = ft_lstat(*lst, index - 1);
		tmp = insert->next;
		insert->next = new;
		insert->next->next = tmp;
	}
}
