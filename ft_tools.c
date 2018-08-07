/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tools.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 10:01:24 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 15:46:43 by brobicho    ###    #+. /#+    ###.fr     */
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
