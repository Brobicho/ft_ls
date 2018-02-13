/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 15:47:42 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 17:52:15 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

void	init_params(t_arg *param)
{
	param->l = 0;
	param->R = 0;
	param->d = 0;
	param->r = 0;
	param->t = 0;
}

void	check_arg(char c, t_arg *param)
{
	if (c == 'd')
		param->d = 1;
	if (c == 'r')
		param->r = 1;
	if (c == 't')
		param->t = 1;
}

void	get_params(int ac, char **av, t_arg *param, int *argc)
{
	int	i;
	int	j;

	*argc = 0;
	init_params(param);
	i = 0;
	while (i != ac)
	{
		if (av[i][0] == '-')
		{
			*argc = *argc + 1;
			j = 0;
			while (av[i][j] != '\0')
			{
				if (av[i][j] == 'l')
					param->l = 1;
				if (av[i][j] == 'R')
					param->R = 1;
				check_arg(av[i][j], param);
				j = j + 1;
			}
		}
		i = i + 1;
	}
}

void	simple_ls(int ac, char **av, t_arg param)
{
	int	i;

	i = 1;
	while (av[i] != 0 && av[i][0] == '-')
		i = i + 1;
	if (ac == 1)
		i = 1;
	if (av[i] != 0 && av[i][0] != '-')
		ft_ls(av[i], param);
	else
		ft_ls(".", param);
}

int		main(int ac, char **av)
{
	int		i;
	int		argc;
	t_arg		param;

	i = 1;
	get_params(ac, av, &param, &argc);
	if (ac - argc <= 2)
		simple_ls(ac, av, param);
	else if (ac - argc > 2)
	{
		while (i != ac)
		{
			if (av[i][0] != '-')
			{
				ft_putendl(av[i]);
				ft_ls(av[i], param);
				ft_putchar('\n');
			}
			i = i + 1;
		}
	}
	return (0);
}
