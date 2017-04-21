/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:00:10 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/21 17:56:07 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char					*ft_strrnchr(const char *s, int c, int n)
{
	int		len;

	len = n;
	while (len && s[len] != (char)c)
		len--;
	if (s[len] == (char)c)
		return ((char *)&s[len]);
	return (NULL);
}

char					*ft_strndup(char const *s1, int n)
{
	char		*new;
	size_t		i;

	i = 0;
	if ((new = ft_strnew(ft_strlen(s1))))
	{
		while (i < (size_t)n)
		{
			new[i] = s1[i];
			i++;
		}
	}
	return (new);
}

char					*getpath(char *path)
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

t_dir					*ft_sort_dirname(t_dir *folder, size_t len)
{
	t_dir	tmp;
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
	ft_putchar_buf('\n');
}

void					tarace(char *av, t_options options, DIR *dir)
{
	struct dirent		*read;
	struct stat			stats;
	char				*str;

	printerr(av, errno, options.l);
	if (options.l)
	{
		dir = opendir(getpath(av));
		while ((read = readdir(dir)))
		{
			if (ft_strcmp(read->d_name, av) == 0)
			{
				if (read->d_type == 4)
					ft_putchar_buf('d');
				else if (read->d_type == 8)
					ft_putchar_buf('-');
				else if (read->d_type == 10)
					ft_putchar_buf('l');
				str = ft_strjoinspe(getpath(av), read->d_name);
				read->d_type == 10 ? lstat(str, &stats) : stat(str, &stats);
				printl(stats, read->d_type, read->d_name);
				free(str);
			}
		}
	}
}

void		printmult(char *av)
{
	ft_putstr_buf("\n");
	ft_putstr_buf(av);
	ft_putstr_buf(":\n");
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
			&& (folder[i].name[0] != '.' && folder[i].name[1] != '\0')
			&& !(folder[i].name[0] == '.'
			&& folder[i].name[1] == '.' && folder[i].name[2] == '\0'))
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

t_dir		*initfolder(t_options options, char *av, DIR *dir, t_dir *folder)
{
	if (options.mult)
		printmult(av);
	options.len = ft_dirlen(dir, options);
	folder = ft_folder(options, av, options.len, -1);
	folder = ft_sort_dirname(folder, options.len);
	if (options.l)
		ft_blocks(av, options.a, folder);
	if (options.t)
		folder = ft_optiont(folder, av, options.a, options.len);
	return (folder);
}

void					ft_ls(t_options options, char *av)
{
	DIR					*dir;
	t_dir				*folder;
	int					flag;
	char				*path;

	path = NULL;
	if (!(dir = opendir(av)))
	{
		tarace(av, options, dir);
		return ;
	}
	folder = NULL;
	folder = initfolder(options, av, dir, folder);
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

size_t					ft_tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int						ft_swaparr(char **tab, int i)
{
	char *tmp;

	tmp = tab[i];
	*tab[i] = *tab[i + 1];
	*tab[i + 1] = *tmp;
	return (1);
}

char					**ft_sort_av(char **av, int i)
{
	char	**tab;
	int		flag;
	int		j;

	tab = malloc(sizeof(char*) * ft_tablen(av) + 1);
	j = -1;
	while (av[i])
	{
		tab[++j] = ft_strdup(av[i]);
		i++;
	}
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while ((size_t)i < ft_tablen(tab) - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				flag = ft_swaparr(tab, i);
			i++;
		}
	}
	tab[i + 1] = NULL;
	return (tab);
}

char				**ft_sort_spe(char **tab, int j)
{
	char	*tmp;
	int		flag;
	size_t	i;

	flag = 1;
	while (flag)
	{
		flag = 0;
		i = j + 1;
		while (i < ft_tablen(tab) - 1)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				flag = 1;
			}
			i++;
		}
	}
	return (tab);
}

void		mainr(t_options options, int ac, char **arg, int i)
{
	if (options.r)
	{
		ac--;
		while (ac >= i)
		{
			ft_ls(options, arg[ac]);
			ac--;
		}
		ft_putchar_buf('\n');
	}
	else
	{
		while (arg[i])
		{
			ft_ls(options, arg[i]);
			i++;
		}
		ft_putchar_buf('\n');
	}
}

int			main(int ac, char **av)
{
	t_options		options;
	int				i;
	char			**arg;

	options = create_struct();
	i = get_options(av, &options);
	if (i == -1)
	{
		ft_putendl("usage: ls [-Ralrt] [file ...]");
		return (0);
	}
	if (i == ac)
	{
		ft_ls(options, ".");
		ft_buf(1, NULL, -1);
		return (0);
	}
	else
		arg = ft_sort_spe(av, i);
	if (ac >= i + 2)
		options.mult = 1;
	mainr(options, ac, arg, i);
	ft_buf(1, NULL, -1);
	return (0);
}
