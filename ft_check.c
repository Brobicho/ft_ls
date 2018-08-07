/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 17:46:50 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/07 19:35:02 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check_blkchr(t_entry *entry)
{
	if (!ft_strcmp(entry->p_nf, "/dev") || !ft_strcmp(entry->p_nf, "/dev/"))
		return (1);
	if ((IS_CHR || IS_BLK) && (g_pad->maj < RDEV_LENMAJ))
		(RDEV_LENMAJ > g_pad->maj) ? (g_pad->maj = RDEV_LENMAJ) : (g_pad->maj);
	if ((IS_CHR || IS_BLK) && (g_pad->min < RDEV_LENMIN))
		(RDEV_LENMIN > g_pad->min) ? (g_pad->min = RDEV_LENMIN) : (g_pad->min);
	return (0);
}

void	ft_check_entry(const char *path, t_opts *flag, t_entry *entry)
{
	(void)flag;
	(void)path;
	if (flag->opt_l)
		option_l(entry, flag);
	else
		ft_print_entry(entry, flag);
	ft_putchar('\n');
}

void	ft_check_opt_g(t_entry *entry, t_opts *flag)
{
	if (S_ISDIR(entry->info.st_mode))
	{
		ft_putcolor(entry->n_f, DIR_COLOR);
		if (flag->opt_p && !flag->opt_l)
			ft_putchar('/');
	}
	else if (S_ISLNK(entry->info.st_mode))
		ft_putcolor(entry->n_f, LNK_COLOR);
	else if (S_ISBLK(entry->info.st_mode))
		ft_putcolor(entry->n_f, BLOCK);
	else if (S_ISCHR(entry->info.st_mode))
		ft_putcolor(entry->n_f, FILE_COLOR);
	else if (S_ISFIFO(entry->info.st_mode))
		ft_putcolor(entry->n_f, FIFO);
	else if (S_ISSOCK(entry->info.st_mode))
		ft_putcolor(entry->n_f, SOCKET);
	else
		ft_putcolor(entry->n_f, NORMAL);
}

int		ft_pwuid_check(int uid)
{
	struct passwd	*pwd;
	int				i;

	if ((pwd = getpwuid(uid)))
	{
		ft_putstr(pwd->pw_name);
		ft_putstr("  ");
		i = ft_strlen(pwd->pw_name);
	}
	else
	{
		ft_putnbr(uid);
		ft_putstr("  ");
		i = ft_nblen(uid);
	}
	return (i);
}

void	ft_checklnk(t_entry *entry)
{
	char	buf[BUF_SIZE];

	if (S_ISLNK(entry->info.st_mode))
	{
		ft_putchar(' ');
		readlink(entry->p_nf, buf, BUF_SIZE);
		ft_putstr("-> ");
		ft_putstr(buf);
	}
}
