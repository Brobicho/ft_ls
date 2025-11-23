/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 16:42:50 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/07 16:40:31 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_pad *g_pad = NULL;

t_opts	init_flag(void)
{
	t_opts	flag;

	flag.opt_l = 0;
	flag.opt_a = 0;
	flag.opt_g = 0;
	flag.opt_rec = 0;
	flag.opt_r = 0;
	flag.opt_t = 0;
	flag.opt_1 = 0;
	flag.opt_p = 0;
	return (flag);
}

int		ft_padinit(void)
{
	if (!(g_pad = malloc(sizeof(t_pad))))
		return (1);
	g_pad->dev = 0;
	g_pad->lnk = 0;
	g_pad->uid = 0;
	g_pad->gid = 0;
	g_pad->size = 0;
	g_pad->blk = 0;
	g_pad->min = 0;
	g_pad->maj = 0;
	return (0);
}
