/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optionl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:58:02 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/24 14:05:58 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void					printl(struct stat stats, int type, char *name)
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
