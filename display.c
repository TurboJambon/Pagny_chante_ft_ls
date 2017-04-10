/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David <David@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 22:51:03 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/10 20:54:52 by David            ###   ########.fr       */
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

void		ft_putdate(char const *str)
{
	int		i;
	char	*ptr;
	char	*tmp;

	if (!str)
		return ;
	i = 4;
	tmp = ft_itoa((time(NULL)) / 31536000 + 1970);
	if ((ptr = ft_strstr(str, tmp)))
		write(1, str + 3, ptr - str - 7);
	else
	{
		ft_putchar(' ');
		while (str[i] != '\n')
		{
			if (i >= 10 && 18 >= i)
				i++;
			else
			{
				ft_putchar(str[i]);
				i++;
			}
		}
	}
	free(tmp);
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
		ft_putchar('\t');
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
	int 	i;
	int		flag;

	flag = 0;
	(options.r) ? (i = options.len - 1) : (i = 0);
	while (folder[i].type && i >= 0)
	{
		if (folder[i].type == 4 && options.R)
			flag = 1;
		ft_displayinfos(options, folder[i], av);
		(options.r) ? i-- : i++;
	}
	return (flag);
}