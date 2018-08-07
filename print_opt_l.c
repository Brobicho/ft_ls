/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_opt_l.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 17:46:50 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/07 13:50:59 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static char		get_file_type(t_entry *entry)
{
	if (S_ISLNK(entry->info.st_mode))
		return ('l');
	if (S_ISBLK(entry->info.st_mode))
		return ('b');
	if (S_ISCHR(entry->info.st_mode))
		return ('c');
	if (S_ISFIFO(entry->info.st_mode))
		return ('f');
	if (S_ISSOCK(entry->info.st_mode))
		return ('s');
	if (S_ISREG(entry->info.st_mode))
		return ('-');
	return ('A');
}

static void		ft_print_pad(int data, int pad)
{
	int i;

	i = ft_nblen(data);
	ft_putsp(i, pad);
	ft_putnbr(data);
	ft_putchar(' ');
}

static void		print_perm(t_entry *entry)
{
	ft_putchar((S_ISDIR(entry->info.st_mode)) ?
			'd' : get_file_type(entry));
	ft_putchar((entry->info.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((entry->info.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((entry->info.st_mode & S_ISUID) ?
			"Ss"[((entry->info.st_mode & S_IXUSR) > 0)] :
			"-x"[((entry->info.st_mode & S_IXUSR) > 0)]);
	ft_putchar((entry->info.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((entry->info.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((entry->info.st_mode & S_ISGID) ?
			"Ss"[((entry->info.st_mode & S_IXGRP) > 0)] :
			"-x"[((entry->info.st_mode & S_IXGRP) > 0)]);
	ft_putchar((entry->info.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((entry->info.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((entry->info.st_mode & S_ISVTX) ?
			"Tt"[((entry->info.st_mode & S_IXOTH) > 0)] :
			"-x"[((entry->info.st_mode & S_IXOTH) > 0)]);
	ft_putchar(' ');
	ft_print_pad(entry->info.st_nlink, g_pad->lnk);
}

static void		print_owner(t_entry *entry)
{
	struct group	*grp;
	int				i;

	i = ft_pwuid_check(entry->info.st_uid);
	ft_putsp(i, g_pad->uid);
	if ((grp = getgrgid(entry->info.st_gid)) != NULL)
	{
		ft_putstr(grp->gr_name);
		ft_putchar(' ');
		i = ft_strlen(grp->gr_name);
	}
	else
	{
		ft_putnbr((int)entry->info.st_gid);
		ft_putchar(' ');
		i = ft_nblen((int)entry->info.st_gid);
	}
	ft_putsp(i, g_pad->gid);
	ft_putchar(' ');
}

void			option_l(t_entry *entry, t_opts *flag)
{
	char	*date;
	int		i;

	if (lstat(entry->p_nf, &entry->info) < 0)
		return ;
	print_perm(entry);
	print_owner(entry);
	if (S_ISCHR(entry->info.st_mode) || S_ISBLK(entry->info.st_mode))
		min_maj(entry);
	else
	{
		i = ft_nblen(entry->info.st_size);
		ft_putsp(i, g_pad->size);
		ft_putnbr((int)entry->info.st_size);
	}
	ft_putchar(' ');
	date = ctime(&entry->info.st_mtime);
	date[16] = '\0';
	ft_putstr(date + 4);
	ft_putchar(' ');
	(flag->opt_g) ? ft_print_entry(entry, flag) : ft_putstr(entry->n_f);
	if (flag->opt_p && S_ISDIR(entry->info.st_mode))
		ft_putchar('/');
	ft_checklnk(entry);
}
