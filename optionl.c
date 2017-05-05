/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optionl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:58:02 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/05 17:32:23 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

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
	options.u ? ft_putdate(time(&stats.st_atime)) :
	ft_putdate(time(&stats.st_mtime));
	ft_putchar_buf('\t');
	ft_color(type, stats.st_mode);
	ft_putstr_buf(name);
	ft_putstr_buf(RESET);
}

void		ft_optl(t_dir folder, char *av, t_options options)
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
	options.u ? ft_putdate(stats.st_atime) :
	ft_putdate(stats.st_mtime);
	ft_putstr_buf("\t");
	free(str);
}
