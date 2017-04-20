/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 22:51:03 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/11 15:35:41 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		ft_color(int type, mode_t mode)
{
	if (type == 4)
		ft_putstr(CYN);
	else if (type == 10)
		ft_putstr(MAG);
	else if (mode & 0x049)
		ft_putstr(RED);
}

void		putyear(time_t date)
{
	char		*str;
	int			i;

	i = 3;
	str = ctime(&date);
	while (i <= 9)
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar(' ');
	write(1, str + 20, 4);
}

void		putdatejambon(time_t date)
{
	int		i;
	char	*str;

	str = ctime(&date);
	i = 4;
	ft_putchar(' ');
	while (i <= 15)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		ft_putdate(time_t date)
{
	if (time(NULL) - date > 15768000)
		putyear(date);
	else
		putdatejambon(date);
}

void	ft_displayname(t_dir folder)
{
	ft_color(folder.type, folder.mode);
	ft_putstr(folder.name);
	ft_putstr(RESET);
}

void	ft_displayinfos(t_options options, t_dir folder, char *av)
{
	int		ret;
	char	buf[256];
	char	*path;

	if (options.l)
	{
		ft_optl(folder, av);
		ft_displayname(folder);
		if (folder.type == 10)
		{
			ft_putstr(" -> ");
			path = ft_strjoinspe(av, folder.name);
			ret = readlink(path, buf, 256);
			buf[ret] = '\0';
			ft_putstr(buf);
			free(path);
		}
		ft_putchar('\n');
	}
	else
	{
		ft_displayname(folder);
		ft_putchar('\t');
	}
	ft_putstr(RESET);
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
		if (folder[i].type == 4 && options.R)
			flag = 1;
		ft_displayinfos(options, folder[i], av);
		(options.r) ? i-- : i++;
	}
	return (flag);
}
