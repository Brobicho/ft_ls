/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 16:07:48 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 18:34:09 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H_
# define FT_LS_H_

# include "libft/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>

typedef struct	s_file
{
  struct dirent	*dir;
  struct s_file	*next;
}				t_file;

typedef struct	s_arg
{
  int		l;
  int		R;
  int		d;
  int		r;
  int		t;
}				t_arg;

typedef struct		s_dirname
{
  char				*name;
  struct s_dirname	*next;
}					t_dirname;

void	ft_putstrnbr(char *str, int nb);
void	ft_putstrsp(char *str);
void	ft_putnbrl(int nb);
int		ft_ls(char *dirname, t_arg param);
int		ft_rev_list(t_file **begin);
t_file	*next_list(t_file *list, struct dirent *dir);
void	ft_sort_list(t_file **list, int r);

#endif
