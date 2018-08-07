/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_sep.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brobicho <brobicho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 15:55:52 by brobicho     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 15:55:55 by brobicho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_sep(char const *s1, char const *sep, char const *s2)
{
	char *str_new;

	if (!(str_new = ft_strnew((ft_strlen(s1) + ft_strlen(s2)
						+ ft_strlen(sep)))))
		return (NULL);
	str_new = ft_strcpy(str_new, s1);
	str_new = ft_strcat((char *)str_new, sep);
	str_new = ft_strcat(str_new, s2);
	return (str_new);
}
