/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optionl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:58:02 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/26 18:03:39 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

/*void	print_acl(char *av)
{
	struct _acl *prout;

	prout = acl_get_file(av, ACL_TYPE_DEFAULT);
	printf("%lu\n", prout->AclRevision);
	//printf("%lu\n", acl_get_file(av, ACL_TYPE_ACCESS));
}*/

void		printl(struct stat stats, int type, char *name)
{
	ft_mode(stats.st_mode);
	ft_putstr_buf("\t");
	ft_putnbr_buf(stats.st_nlink);
	ft_putstr_buf("\t");
	ft_putstr_buf(getpwuid(stats.st_uid)->pw_name);
	ft_putstr_buf("  ");
	ft_putstr_buf(getgrgid(getpwuid(stats.st_uid)->pw_gid)->gr_name);
	ft_putstr_buf("\t");
	ft_putnbr_buf(stats.st_size);
	ft_putstr_buf("\t");
	ft_putdate(time(&stats.st_mtime));
	ft_putchar_buf('\t');
	ft_color(type, stats.st_mode);
	ft_putstr_buf(name);
	ft_putstr_buf(RESET);
}

void		ft_optl(t_dir folder, char *av)
{
	struct stat	stats;
	char		*str;

	if (folder.type == 4)
		ft_putchar_buf('d');
	else if (folder.type == 8)
		ft_putchar_buf('-');
	else if (folder.type == 10)
		ft_putchar_buf('l');
	str = ft_strjoinspe(av, folder.name);
	folder.type == 10 ? lstat(str, &stats) : stat(str, &stats);
	ft_mode(stats.st_mode);
	//print_acl(av);
	ft_putstr_buf("\t");
	ft_putnbr_buf(stats.st_nlink);
	ft_putstr_buf("\t");
	ft_putstr_buf(getpwuid(stats.st_uid)->pw_name);
	ft_putstr_buf("  ");
	ft_putstr_buf(getgrgid(getpwuid(stats.st_uid)->pw_gid)->gr_name);
	ft_putstr_buf("\t");
	ft_putnbr_buf(stats.st_size);
	ft_putstr_buf("\t");
	ft_putdate(stats.st_mtime);
	ft_putstr_buf("\t");
	free(str);
}
