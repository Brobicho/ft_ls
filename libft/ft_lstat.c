/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstat.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 03:50:03 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 15:52:54 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *lst, size_t index)
{
	while (lst && index--)
		lst = lst->next;
	return (lst);
}
