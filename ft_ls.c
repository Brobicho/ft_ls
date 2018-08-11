/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 03:36:14 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/11 14:31:02 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_recursive(t_list *tmp, t_opts *flag)
{
	t_entry *entry;
	t_entry *next;

	while (tmp)
	{
		if (tmp->next)
			next = tmp->next->content;
		entry = tmp->content;
		if (S_ISDIR(entry->info.st_mode) && !ft_strequ(entry->n_f, ".")
			&& !ft_strequ(entry->n_f, ".."))
			ft_print_dir_contents(entry->p_nf, flag, 1);
		if (tmp->next && S_ISDIR(next->info.st_mode))
			ft_putchar('\n');
		g_pad->blk = 0;
		tmp = tmp->next;
	}
}

void	ft_ls_entries(t_opts *flag, t_list *lst, const char *path)
{
	t_list	*tmp;

	tmp = lst;
	if (flag->opt_l)
		print_tot(g_pad->blk);
	while (tmp)
	{
		ft_check_entry(path, flag, tmp->content);
		tmp = tmp->next;
	}
	tmp = lst;
	if (flag->opt_rec)
		ft_recursive(tmp, flag);
}

void	ft_ls(t_opts *flag, t_list *lst, int ac)
{
	t_entry *entry;
	t_list	*tmp;
	t_entry *prev;
	t_entry *next;
	int		print_dn;

	print_dn = 0;
	tri_content(&lst, flag);
	tmp = lst;
	while (lst)
	{
		if (lst->next)
		{
			prev = lst->content;
			next = lst->next->content;
		}
		entry = lst->content;
		if (ac > 2)
			print_dn = 1;
		ft_checkdir(entry, flag, print_dn);
		ft_newline_ifdir(lst, prev, next);
		g_pad->blk = 0;
		lst = lst->next;
	}
	ft_lstfree(tmp);
}
