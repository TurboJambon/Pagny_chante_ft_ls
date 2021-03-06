/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 22:51:03 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/08 17:47:11 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	printmult(char *av)
{
	ft_putstr_buf("\n");
	ft_putstr_buf(av);
	ft_putstr_buf(":\n");
}

void	ft_displayname(t_dir folder, t_options options)
{
	ft_color(folder.type, folder.mode);
	ft_putstr_buf(folder.name);
	ft_putstr_buf(RESET);
	if (options.p && folder.type == 4)
		ft_putchar_buf('/');
}

void	lsfile(char *av, t_options options)
{
	struct stat			stats;
	char				*str;
	int					type;

	printerr(av, errno, options.l);
	if (errno == 13)
		return ;
	if (options.l)
	{
		str = ft_strjoinspe(getpath(av), ft_strrchr(av, '/'));
		str == NULL ? lstat(av, &stats) : lstat(str, &stats);
		type = typestat(stats);
		printtype(type);
		printl(stats, type, av, options);
		free(str);
		ft_putstr_buf("\n\n");
	}
}

void	ft_displayinfos(t_options options, t_dir folder, char *av)
{
	int		ret;
	char	buf[256];
	char	*path;

	if (options.l)
	{
		ft_optl(folder, av, options);
		ft_displayname(folder, options);
		if (folder.type == 10)
		{
			ft_putstr_buf(" -> ");
			path = ft_strjoinspe(av, folder.name);
			ret = readlink(path, buf, 256);
			buf[ret] = '\0';
			ft_putstr_buf(buf);
			free(path);
		}
		ft_putchar_buf('\n');
	}
	else
	{
		ft_displayname(folder, options);
		ft_putchar_buf('\t');
	}
	ft_putstr_buf(RESET);
}

int		ft_affls(t_dir *folder, t_options options, char *av)
{
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	if (options.r)
		i = options.len - 1;
	while (folder[i].type && i >= 0)
	{
		if (folder[i].type == 4 && options.r2)
			flag = 1;
		ft_displayinfos(options, folder[i], av);
		(options.r) ? i-- : i++;
	}
	if (!options.l)
		ft_putchar_buf('\n');
	return (flag);
}
