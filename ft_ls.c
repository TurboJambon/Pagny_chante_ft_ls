/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:00:10 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/08 23:16:03 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_dir		*ft_sort_dirname(t_dir *folder, size_t len)
{
	t_dir 	tmp;
	int		flag;
	size_t	i;

	if (!folder->type)
		return (folder);
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i <= len && folder[i + 1].type)
		{
			if (strcmp(folder[i].name, folder[i + 1].name) > 0)
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

void		ft_color(int type, mode_t mode)
{
	if (type == 4)
		ft_putstr(CYN);
	else if (type == 10)
		ft_putstr(MAG);
	else if (mode & 0x049)
		ft_putstr(RED);
}

int		ft_affls(t_dir *folder, t_options options, char *av)
{
	int 	i;
	int		flag;
	int 	ret;
	char 	buf[256];

	flag = 0;
	(options.r) ? (i = options.len - 1) : (i = 0);
	while (folder[i].type && i >= 0)
	{
		if (folder[i].type == 4 && options.R)
			flag = 1;
		if (options.l)
		{
			ft_optl(folder[i], av);
			ft_putchar('\t');
			ft_color(folder[i].type, folder[i].mode);
			ft_putstr(folder[i].name);
			ft_putstr(RESET);
			if (folder[i].type == 10)
			{
				ft_putstr(" -> ");
				ret = readlink(ft_strjoinspe(av, folder[i].name), buf, 300);
				buf[ret] = '\0';
				ft_putstr(buf);
			}
			ft_putchar('\n');
		}
		else
		{
			ft_color(folder[i].type, folder[i].mode);
			ft_putstr(folder[i].name);
			ft_putchar('\t');
			ft_putstr(RESET);
		}
		(options.r) ? i-- : i++;
	}
	return (flag);
}

void 		ft_ls(t_options options, char *av)
{
	DIR 				*dir;
	t_dir 				*folder;
	int 				i;		// OUT
	int 				flag;
	char 				*path;

	path = NULL;
	if (!(dir = opendir(av)))
	{
		printerr(av, errno);
		return ;
	}
	if (options.mult)
		{
			ft_putstr("\n");
			ft_putstr(av);
			ft_putstr(":\n");
		}
	options.len = ft_dirlen(dir, options);
	folder = ft_folder(options, av, options.len);
	folder = ft_sort_dirname(folder, options.len);
	flag = 0;
	i = 0;
	if (options.l)
		ft_blocks(av, options.a, folder);
	if (options.t)
		folder = ft_optiont(folder, av, options.a, options.len);
	if (ft_affls(folder, options, av))
		flag = 1;

	ft_putchar('\n');
	i = 0;
	if (flag)
	{ // options.len - folder - options - path - av
		(options.r) ? (i = options.len - 1) : (i = 0); 
		while (folder[i].type && i >= 0)
		{
			if (folder[i].type == 4
				&& (folder[i].name[0] != '.' && folder[i].name[0] != '\0')
				&& !(folder[i].name[0] == '.' 
				&& folder[i].name[1] == '.' && folder[i].name[2] == '\0'))
			{
				path = ft_strjoinspe(av, folder[i].name);
				ft_putstr(path);
				ft_putstr(":\n");
				ft_ls(options, path);
				ft_strdel(&path);
			}	
			options.r ? i-- : i++;
		}
	}
	freedir(folder);
	free(folder);
	if (options.mult)
		ft_putstr("\n");	
}

int 		main(int ac, char **av)
{  

	t_options options;
	int i;

	options = create_struct();
	i = get_options(av, &options);
	if (i == ac)
	{
		ft_ls(options, ".");
	}
	(ac >= i + 2) ? (options.mult) = 1 : (options.mult = 0);
	while (av[i])
	{
		ft_ls(options, av[i]);
		i++;
	}
	return (0);
}