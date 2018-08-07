/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 15:20:33 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 15:53:23 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_path(const char *path)
{
	ft_putstr_fd("ft_ls: ", 2);
	perror(path);
}

int		error_flag(char *str, int i)
{
	ft_putstr_fd("ft_ls: illegal flag -- ", 2);
	ft_putchar_fd(str[i], 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ft_ls [-GRalprt1] [file ...]", 2);
	return (0);
}
