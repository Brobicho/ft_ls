/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tri_t.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 09:11:05 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2025/02/20 15:52:44 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int	sort_ascii_asc(void *ct1, size_t pff, void *ct2, size_t pff_1)
{
	const t_entry *entry1 = ct1;
	const t_entry *entry2 = ct2;

	(void)pff;
	(void)pff_1;
	return (ft_strcmp(entry1->n_f, entry2->n_f) > 0);
}

static int	sort_ascii_des(void *ct1, size_t pff, void *ct2, size_t pff_1)
{
	const t_entry *entry1 = ct1;
	const t_entry *entry2 = ct2;

	(void)pff;
	(void)pff_1;
	return (ft_strcmp(entry2->n_f, entry1->n_f) > 0);
}

static int	sort_time_asc(void *ct1, size_t pff, void *ct2, size_t pff_1)
{
	const t_entry	*entry1 = ct1;
	const t_entry	*entry2 = ct2;
	long int		c1;
	long int		c2;

	c1 = entry1->MTIME_S;
	c2 = entry2->MTIME_S;
	if (c1 == c2)
	{
		c1 = entry1->MTIME_NS;
		c2 = entry2->MTIME_NS;
		if (c1 == c2)
			return (sort_ascii_asc(ct1, pff, ct2, pff_1));
	}
	return (c1 < c2);
}

static int	sort_time_des(void *ct1, size_t pff, void *ct2, size_t pff_1)
{
	const t_entry	*entry1 = ct1;
	const t_entry	*entry2 = ct2;
	long int		c1;
	long int		c2;

	c1 = entry1->MTIME_S;
	c2 = entry2->MTIME_S;
	if (c1 == c2)
	{
		c1 = entry1->MTIME_NS;
		c2 = entry2->MTIME_NS;
		if (c1 == c2)
			return (sort_ascii_des(ct1, pff, ct2, pff_1));
	}
	return (c2 < c1);
}

void	tri_content(t_list **lst, const t_opts *flag)
{
	if (flag->opt_r && flag->opt_t)
		ft_lstsort(lst, sort_time_des);
	else if (flag->opt_r)
		ft_lstsort(lst, sort_ascii_des);
	else if (flag->opt_t)
		ft_lstsort(lst, sort_time_asc);
	else
		ft_lstsort(lst, sort_ascii_asc);
}

