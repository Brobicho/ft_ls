/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 17:46:50 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/07 19:38:15 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	ft_dn_check(int print_dn, const char *path)
{
	if (print_dn)
		print_path(path);
}

void	ft_putcolor(char *str, char *c)
{
	int i;

	i = 0;
	ft_putstr(c);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putstr(C_RESET);
}

void	print_tot(int pad)
{
	ft_putstr("total ");
	ft_putnbr(pad);
	ft_putchar('\n');
}

void	print_path(const char *path)
{
	ft_putstr((char *)path);
	ft_putendl(":");
}

void	ft_print_dir_contents(const char *path, t_opts *flag, int print_dn)
{
	DIR				*save_dir;
	struct dirent	*ret;
	t_list			*lst;

	lst = NULL;
	save_dir = opendir(path);
	if (save_dir)
	{
		ft_dn_check(print_dn, path);
		ret = readdir(save_dir);
		while (ret != NULL)
		{
			if (flag->opt_a || ret->d_name[0] != '.')
				ft_new_entry(ret->d_name, path, &lst);
			ret = readdir(save_dir);
		}
		closedir(save_dir);
		tri_content(&lst, flag);
		ft_ls_entries(flag, lst, path);
	}
	else
		error_path(path);
	ft_lstfree(lst);
}

void	ft_print_entry(t_entry *entry, t_opts *flag)
{
	if (flag->opt_g)
		ft_check_opt_g(entry, flag);
	else
	{
		ft_putstr(entry->n_f);
		if (S_ISDIR(entry->info.st_mode) && flag->opt_p)
			ft_putchar('/');
	}
}
