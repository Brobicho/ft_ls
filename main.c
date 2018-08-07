/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 11:18:44 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/07 16:49:14 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int		parse_opt(char *str, t_opts *flag)
{
	int	i;

	i = 0;
	while (str[++i])
	{
		if (str[i] == 'l')
			flag->opt_l = 1;
		else if (str[i] == 'G')
			flag->opt_g = 1;
		else if (str[i] == 'R')
			flag->opt_rec = 1;
		else if (str[i] == 'a')
			flag->opt_a = 1;
		else if (str[i] == 'r')
			flag->opt_r = 1;
		else if (str[i] == 't')
			flag->opt_t = 1;
		else if (str[i] == '1')
			flag->opt_1 = 1;
		else if (str[i] == 'p')
			flag->opt_p = 1;
		else
			return (error_flag(str, i));
	}
	return (1);
}

int				main(int ac, char **av)
{
	int		i;
	t_opts	flag;
	t_list	*save;
	int		error;

	i = 1;
	error = 0;
	flag = init_flag();
	if (ft_padinit())
		return (1);
	save = NULL;
	while (i < ac && (av[i][0] == '-' && av[i][1]))
	{
		if (!parse_opt(av[i++], &flag))
			return (1);
	}
	while (i < ac)
	{
		if (!ft_new_entry(av[i++], NULL, &save))
			error++;
	}
	if (!save && !error)
		ft_new_entry(".", NULL, &save);
	ft_ls(&flag, save, ac);
	return (0);
}
