/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 15:49:01 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/11 21:10:30 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

char		*fusion_path_and_name(char *dirname, char *filename)
{
	char		*str;

	str = malloc(ft_strlen(dirname) + ft_strlen(filename) + 1);
	ft_strcpy(str, dirname);
	ft_strcat(str, "/");
	ft_strcat(str, filename);
	return (str);
}

int		calc_total(t_file *files, char *dirname, int l)
{
	t_file		*tmp;
	int			total;
	char		*str;
	struct stat	buf;


	if (l != 1)
		return (0);
	total = 0;
	tmp = files;
	while (tmp != '\0')
	{
		str = fusion_path_and_name(dirname, tmp->dir->d_name);
		stat(str, &buf);
		total = total + buf.st_blocks;
		tmp = tmp->next;
		free(str);
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
	return (0);
}

char	*convert_time(char *str)
{
	char	*time;

	time = str + 4;
	time[12] ='\0';
	return (time);
}

void		print_files(char *dirname, t_file *files, int l)
{
	struct stat		*buf;
	char			*str;
	struct group	*grp;
	struct passwd	*pwd;

	buf = malloc(sizeof(*buf));
	calc_total(files, dirname, l);
	while (files)
	{
		if (l == 1)
		{
			str = fusion_path_and_name(dirname, files->dir->d_name);
			lstat(str, buf);
			grp = getgrgid(buf->st_gid);
			pwd = getpwuid(buf->st_uid);
			if (S_ISDIR(buf->st_mode))
				ft_putchar('d');
			else if (S_ISLNK(buf->st_mode))
				ft_putchar('l');
			else
				ft_putchar('-');
			(S_IRUSR & buf->st_mode) ? ft_putchar('r') : ft_putchar('-');
			(S_IWUSR & buf->st_mode) ? ft_putchar('w') : ft_putchar('-');
			(S_IXUSR & buf->st_mode) ? ft_putchar('x') : ft_putchar('-');
			(S_IRGRP & buf->st_mode) ? ft_putchar('r') : ft_putchar('-');
			(S_IWGRP & buf->st_mode) ? ft_putchar('w') : ft_putchar('-');
			(S_IXGRP & buf->st_mode) ? ft_putchar('x') : ft_putchar('-');
			(S_IROTH & buf->st_mode) ? ft_putchar('r') : ft_putchar('-');
			(S_IWOTH & buf->st_mode) ? ft_putchar('w') : ft_putchar('-');
			(S_IXOTH & buf->st_mode) ? ft_putchar('x') : ft_putchar('-');
			ft_putchar(' ');
			ft_putnbr(buf->st_nlink);
			ft_putchar(' ');
			ft_putstrsp(pwd->pw_name);
			ft_putstrsp(grp->gr_name);
			ft_putnbr(buf->st_size);
			ft_putchar(' ');
			ft_putstrsp(convert_time(ctime(&buf->st_mtime)));
			free(str);
		}
		ft_putendl(files->dir->d_name);
		files = files->next;
	}
}

int		ft_ls(char *dirname, t_arg param)
{
	struct dirent	*ft_dir;
	DIR				*dir;
	t_file			*files;

	files = 0;
	dir = opendir(dirname);
	if (dir == '\0')
	{
		perror("Error");
		return (1);
	}
	while ((ft_dir = readdir(dir)) != '\0')
	{
		if (ft_dir->d_name[0] != '.' || (param.d == 1 && ft_dir->d_name[0] == '.'
					&& ft_dir->d_name[1] == '\0'))
			files = next_list(files, ft_dir);
	}
	ft_sort_list(&files, param.r);
	print_files(dirname, files, param.l);
	return (0);
}
