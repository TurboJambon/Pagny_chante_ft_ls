/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 22:51:03 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/21 20:04:38 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		ft_color(int type, mode_t mode)
{
	if (type == 4)
		ft_putstr_buf(CYN);
	else if (type == 10)
		ft_putstr_buf(MAG);
	else if (mode & 0x049)
		ft_putstr_buf(RED);
}

void		putyear(time_t date)
{
	char		*str;
	int			i;

	i = 3;
	str = ctime(&date);
	while (i <= 9)
	{
		ft_putchar_buf(str[i]);
		i++;
	}
	ft_putchar_buf(' ');
	ft_buf(1, str + 20, 4);
}

void		putdatejambon(time_t date)
{
	int		i;
	char	*str;

	str = ctime(&date);
	i = 4;
	ft_putchar_buf(' ');
	while (i <= 15)
	{
		ft_putchar_buf(str[i]);
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
	ft_putstr_buf(folder.name);
	ft_putstr_buf(RESET);
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
		ft_displayname(folder);
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
		if (folder[i].type == 4 && options.R)
			flag = 1;
		ft_displayinfos(options, folder[i], av);
		(options.r) ? i-- : i++;
	}
	ft_putchar_buf('\n');
	return (flag);
}
