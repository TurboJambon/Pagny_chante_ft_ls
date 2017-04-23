/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 22:51:03 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/22 15:57:33 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

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
		if (folder[i].type == 4 && options.r2)
			flag = 1;
		ft_displayinfos(options, folder[i], av);
		(options.r) ? i-- : i++;
	}
	if (!options.l)
		ft_putchar_buf('\n');
	return (flag);
}
