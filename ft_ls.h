/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/10/10 17:46:50 by ckupfers     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/11 14:31:26 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <locale.h>
# include <langinfo.h>
# include <stdint.h>

# define LNK_COLOR		RED
# define DIR_COLOR		GREEN
# define FILE_COLOR		BLUE
# define NORMAL			CYAN
# define SOCKET			MAGENTA
# define BLOCK			YELLOW
# define FIFO			WHITE

# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define MAGENTA		"\x1b[35m"
# define CYAN			"\x1b[36m"
# define WHITE			"\x1b[37m"
# define C_RESET		"\x1b[0m"

# define BUF_SIZE 0xffff

# define RDEV_LENMIN	ft_nblen(minor(entry->info.st_rdev))
# define RDEV_LENMAJ	ft_nblen(major(entry->info.st_rdev))
# define IS_CHR			S_ISCHR(entry->info.st_mode)
# define IS_BLK			S_ISBLK(entry->info.st_mode)
# define IS_SCK			S_ISSOCK(entry->info.st_mode)
# define IS_DIR			S_ISDIR(entry->info.st_mode)

typedef struct	s_opts
{
	int			opt_g;
	int			opt_l;
	int			opt_a;
	int			opt_p;
	int			opt_rec;
	int			opt_r;
	int			opt_t;
	int			opt_1;
}				t_opts;

typedef struct	s_entry
{
	char		*n_f;
	char		*p_nf;
	char		*link;
	struct stat	info;
}				t_entry;

typedef struct	s_pad
{
	int			dev;
	int			lnk;
	int			uid;
	int			gid;
	int			size;
	int			blk;
	int			min;
	int			maj;
}				t_pad;

t_pad			*g_pad;
t_opts			init_flag(void);
int				ft_pwuid_check(int uid);
int				ft_padinit(void);
int				ft_nblen(int nb);
void			ft_dn_check(int print_dn, const char *path);
void			ft_checkdir(t_entry *entry, t_opts *flag, int print_dn);
void			ft_newline_ifdir(t_list *lst, t_entry *prev, t_entry *next);
void			ft_putcolor(char *str, char *c);
void			ft_check_opt_g(t_entry *entry, t_opts *flag);
void			ft_putsp(int j, int k);
void			ft_printcolor(char *str, char *s);
void			ft_lstfree(t_list *lst);
void			ft_free_entry(t_entry *entry);
void			ft_recursive(t_list *tmp, t_opts *flag);
void			ft_ls(t_opts *flag, t_list *save, int ac);
void			ft_ls_entries(t_opts *flag, t_list *lst, const char *path);
void			tri_content(t_list **lst, const t_opts *flag);
void			option_l(t_entry *entry, t_opts *flag);
void			error_path(const char *path);
void			print_path(const char *path);
void			ft_print_entry(t_entry *entry, t_opts *flag);
void			ft_checklnk(t_entry *entry);
void			ft_check_entry(const char *path, t_opts *flag, t_entry *entry);
void			ft_print_dir_contents(const char *path,
				t_opts *flag, int print_dn);
void			ft_add_entry(t_list **lst, char *name_file, char *path);
void			min_maj(t_entry *entry);
void			print_tot(int pad);
int				error_flag(char *str, int i);
int				ft_new_entry(char *name_file, const char *path, t_list **lst);
int				ft_check_blkchr(t_entry *entry);

#endif
