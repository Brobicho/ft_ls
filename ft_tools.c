/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tools.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 10:01:24 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/11 14:30:40 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_nblen(int nb)
{
	int i;

	i = 1;
	while (nb / 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	ft_putsp(int j, int k)
{
	while (j < k)
	{
		ft_putchar(' ');
		j++;
	}
}

void	ft_checkdir(t_entry *entry, t_opts *flag, int print_dn)
{
	if (IS_DIR && !ft_strcmp(entry->p_nf, "."))
		ft_print_dir_contents(entry->p_nf, flag, 0);
	else if (IS_DIR && ft_strcmp(entry->p_nf, "."))
		ft_print_dir_contents(entry->p_nf, flag, print_dn);
	else
		ft_check_entry(NULL, flag, entry);
}

void	ft_dn_check(int print_dn, const char *path)
{
	if (print_dn)
		print_path(path);
}

void	ft_newline_ifdir(t_list *lst, t_entry *prev, t_entry *next)
{
	if (lst->next
		&& ((S_ISDIR(prev->info.st_mode) || (S_ISDIR(next->info.st_mode)))))
		ft_putchar('\n');
}
