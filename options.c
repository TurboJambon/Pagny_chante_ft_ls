/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David <David@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 22:14:28 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/10 20:54:44 by David            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_dir		*ft_tsort(t_dir *folder, int len)
{
	int		flag;
	int		i;
	t_dir	tmp;

	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i <= len - 2)
		{
			if (folder[i].time < folder[i + 1].time)
			{
				tmp = folder[i];
				folder[i] = folder[i + 1];
				folder[i + 1] = tmp;
				flag = 1;
			}
			i++;
		}
	}
	return (folder);
}

t_dir		*ft_optiont(t_dir *folder, char *path, int a, int len)
{
	struct stat		stats;
	int				i;
	char			*str;

	i = 0;
	while (folder[i].type)
	{
		if ((folder[i].name[0] == '.' && a)
			|| a
			|| (a == 0 && folder[i].name[0] != '.'))
		{
			str = ft_strjoinspe(path, folder[i].name);
			stat(str, &stats);
			folder[i].time = stats.st_mtime;
			free(str);
		}
		i++;
	}
	return (ft_tsort(folder, len));
}

void		ft_optl(t_dir folder, char *av)
{
	struct stat	stats;
	char		*str;

	if (folder.type == 4)
		ft_putchar('d');
	else if (folder.type == 8)
		ft_putchar('-');
	else if (folder.type == 10)
		ft_putchar('l');
	str = ft_strjoinspe(av, folder.name);
	folder.type == 10 ? lstat(str, &stats) : stat(str, &stats);
	ft_mode(stats.st_mode);
	ft_putstr("\t");
	ft_putnbr(stats.st_nlink);
	ft_putstr("\t");
	ft_putstr(getpwuid(stats.st_uid)->pw_name);
	ft_putstr("  ");
	ft_putstr(getgrgid(getpwuid(stats.st_uid)->pw_gid)->gr_name);
	ft_putstr("\t");
	ft_putnbr(stats.st_size);
	ft_putstr("\t");
	ft_putdate(ctime(&stats.st_mtime));
	free(str);
}

void		ft_blocks(char *path, int a, t_dir *folder)
{
	struct stat		stats;
	unsigned long	blocks;
	int				i;
	char			*var;

	i = 0;
	blocks = 0;
	if (!folder[i].type)
		return ;
	while (folder[i].type)
	{
		if ((folder[i].name[0] == '.' && a) || a
			|| (a == 0 && folder[i].name[0] != '.'))
		{
			var = ft_strjoinspe(path, folder[i].name);
			folder[i].type == 10 ? lstat(var, &stats) : stat(var, &stats);
			free(var);
			blocks += stats.st_blocks;
		}
		i++;
	}
	ft_putstr("total ");
	ft_putnbr(blocks);
	ft_putchar('\n');
}
