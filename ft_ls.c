/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:00:10 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/05 18:51:37 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char				*getpath(char *path)
{
	int		len;
	char	*ptr;
	char	*ret;

	if (!path)
		return (ft_strdup("."));
	len = ft_strlen(path) - 1;
	while (path[len] == '/')
		len--;
	if (!(ptr = ft_strrnchr(path, '/', len + 1)))
		return (".");
	len = ptr - path;
	ret = ft_strndup(path, len);
	return (ret);
}

t_dir				*initfolder(t_options options, char *av, t_dir *folder)
{
	if (options.mult)
		printmult(av);
	folder = ft_folder(options, av, options.len, -1);
	if (!options.f)
		folder = ft_sort_dirname(folder, options.len);
	if (options.l)
		ft_blocks(av, options.a, folder);
	if (options.t)
		folder = ft_optiont(folder, av, options, options.len);
	return (folder);
}

void				ft_ls(t_options options, char *av)
{
	DIR					*dir;
	t_dir				*folder;
	int					flag;
	char				*path;

	path = NULL;
	if (!(dir = opendir(av)))
	{
		lsfile(av, options, dir);
		return ;
	}
	folder = NULL;
	options.len = ft_dirlen(dir, options);
	folder = initfolder(options, av, folder);
	flag = 0;
	if (ft_affls(folder, options, av))
		flag = 1;
	ft_putchar_buf('\n');
	if (flag)
		options_r(options, folder, av, path);
	freedir(folder);
	free(folder);
	if (options.mult)
		ft_putstr_buf("\n");
}

void				mainr(t_options options, int ac, char **arg, int i)
{
	if (options.r)
	{
		ac--;
		while (ac >= i)
		{
			ft_ls(options, arg[ac]);
			ac--;
		}
	}
	else
	{
		while (arg[i])
		{
			ft_ls(options, arg[i]);
			i++;
		}
	}
}

int					main(int ac, char **av)
{
	t_options		options;
	int				i;

	options = create_struct();
	i = get_options(av, &options);
	if (i == -1)
		return (puterr("usage: ls [-"OPTIONS"] [file ...]\n"));
	if (options.f)
		del_options(&options);
	if (ac >= i + 2)
		options.mult = 1;
	if (i == ac)
	{
		ft_ls(options, ".");
		ft_buf(1, NULL, -1);
		return (0);
	}
	else
		ft_sort_spe(av + i, ac, i);
	mainr(options, ac, av, i);
	multnewline(options);
	ft_buf(1, NULL, -1);
	return (0);
}
