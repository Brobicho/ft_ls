/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_min_maj.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 17:46:50 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 15:48:29 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	min_maj(t_entry *entry)
{
	int i;

	i = ft_nblen(major(entry->info.st_rdev));
	while (i < g_pad->maj)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr(major(entry->info.st_rdev));
	ft_putstr(", ");
	i = ft_nblen(minor(entry->info.st_rdev));
	while (i < g_pad->min)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr(minor(entry->info.st_rdev));
}
