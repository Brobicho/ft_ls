/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_entry.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 17:46:50 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/07 13:46:46 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_padinfo(t_entry *entry)
{
	struct passwd	*pwd;
	struct group	*grp;
	int				i;

	i = g_pad->min;
	if (!(ft_check_blkchr(entry)))
		g_pad->blk += entry->info.st_blocks;
	if ((pwd = getpwuid(entry->info.st_uid)) != NULL)
		i = ft_strlen(pwd->pw_name);
	else
		i = ft_nblen((int)entry->info.st_uid);
	if (i > g_pad->uid)
		g_pad->uid = i;
	if ((grp = getgrgid(entry->info.st_gid)) != NULL)
		i = ft_strlen(grp->gr_name);
	else
		i = ft_nblen((int)entry->info.st_gid);
	if (i > g_pad->gid)
		g_pad->gid = i;
	if (ft_nblen(entry->info.st_nlink) > g_pad->lnk)
		g_pad->lnk = ft_nblen(entry->info.st_nlink);
	if (ft_nblen(entry->info.st_size) > g_pad->size)
		g_pad->size = ft_nblen(entry->info.st_size);
}

int		ft_new_entry(char *name_file, const char *path, t_list **lst)
{
	t_entry	*entry;
	t_list	*new;

	entry = malloc(sizeof(t_entry));
	entry->n_f = ft_strdup(name_file);
	if (path != NULL)
		entry->p_nf = ft_strjoin_sep(path, "/", name_file);
	else
		entry->p_nf = ft_strdup(name_file);
	if (lstat(entry->p_nf, &entry->info) == -1)
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(entry->p_nf);
		return (0);
	}
	else
	{
		ft_padinfo(entry);
		new = ft_lstnew(entry, sizeof(t_entry));
		new->next = *lst;
		*lst = new;
	}
	return (1);
}

void	ft_add_entry(t_list **lst, char *name_file, char *path)
{
	t_entry entry;

	entry.n_f = ft_strdup(name_file);
	if (path)
		entry.p_nf = ft_strjoin_sep(path, "/", name_file);
	else
		entry.p_nf = ft_strdup(name_file);
	(*lst)->content = (void*)(&entry);
	(*lst)->content_size = sizeof(&entry);
}
