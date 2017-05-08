/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optionl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:58:02 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/08 17:37:12 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		printacl(char *path, char *file)
{
	acl_t		acl;
	ssize_t		aclvalue;
	char		*str;

	str = ft_strjoinspe(path, file);
	aclvalue = listxattr(str, NULL, 1, XATTR_NOFOLLOW);
	if (aclvalue > 0)
		ft_putchar_buf('@');
	else
	{
		acl = acl_get_file(str, ACL_TYPE_EXTENDED);
		if (acl != NULL)
			ft_putchar_buf('+');
		else
			ft_putchar_buf(' ');
		acl_free((void*)acl);
	}
	free(str);
}

void		printtype(int type)
{
	static char			vtype[13] = "?fc-d-b---l-s";

	if (type >= 0 && type <= 13)
		ft_putchar_buf(vtype[type]);
	else
		ft_putchar_buf('?');
}

void		printl(struct stat stats, int type, char *name, t_options options)
{
	ft_mode(stats.st_mode);
	ft_putstr_buf("\t");
	ft_putnbr_buf(stats.st_nlink);
	ft_putstr_buf("\t");
	if (!options.g)
		ft_putstr_buf(getpwuid(stats.st_uid)->pw_name);
	ft_putstr_buf("  ");
	ft_putstr_buf(getgrgid(getpwuid(stats.st_uid)->pw_gid)->gr_name);
	ft_putstr_buf("\t");
	ft_putnbr_buf(stats.st_size);
	ft_putstr_buf("\t");
	options.u ? ft_putdate(stats.st_atime) : ft_putdate(stats.st_mtime);
	ft_putchar_buf('\t');
	ft_color(type, stats.st_mode);
	ft_putstr_buf(name);
	ft_putstr_buf(RESET);
}

void		ft_optl(t_dir folder, char *av, t_options options)
{
	struct stat	stats;
	char		*str;

	printtype(folder.type);
	str = ft_strjoinspe(av, folder.name);
	folder.type == 10 ? lstat(str, &stats) : stat(str, &stats);
	ft_mode(stats.st_mode);
	printacl(av, folder.name);
	ft_putstr_buf("\t");
	ft_putnbr_buf(stats.st_nlink);
	ft_putstr_buf("\t");
	options.g ? NULL : ft_putstr_buf(getpwuid(stats.st_uid)->pw_name);
	ft_putstr_buf("  ");
	ft_putstr_buf(getgrgid(getpwuid(stats.st_uid)->pw_gid)->gr_name);
	ft_putstr_buf("\t");
	ft_putnbr_buf(stats.st_size);
	ft_putstr_buf("\t");
	options.u ? ft_putdate(stats.st_atime) : ft_putdate(stats.st_mtime);
	ft_putstr_buf("\t");
	free(str);
}
