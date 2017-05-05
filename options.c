/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 22:14:28 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/05 15:57:03 by dchirol          ###   ########.fr       */
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

void		options_r(t_options options, t_dir *folder, char *av, char *path)
{
	int	i;

	i = 0;
	if (options.r)
		i = options.len - 1;
	while (folder[i].type && i >= 0)
	{
		if (folder[i].type == 4
			&& !(folder[i].name[0] == '.' && folder[i].name[1] == '\0')
			&& !(folder[i].name[0] == '.' && folder[i].name[1] == '.' && folder[i].name[2] == '\0'))
		{
			path = ft_strjoinspe(av, folder[i].name);
			ft_putstr_buf(path);
			ft_putstr_buf(":\n");
			ft_ls(options, path);
			ft_strdel(&path);
		}
		options.r ? i-- : i++;
	}
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
	ft_putstr_buf("total ");
	ft_putnbr_buf(blocks);
	ft_putchar_buf('\n');
}
