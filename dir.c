/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:33:13 by dchirol           #+#    #+#             */
/*   Updated: 2017/03/19 20:05:05 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_putdate(char const *str)
{
	int i;
	char *ptr;

	if (!str)
		return ;
	i = 4;
	if ((ptr = ft_strstr(str , "2017")))
		write(1, str + 3, ptr - str - 7);
	else 
		while (str[i] != '\n')
		{
			ft_putchar(str[i]);
			i++;
		}
}

void ft_mode(mode_t n)
{
	mode_t i;

	i = 0x100;
	while (i > 0)
	{
		if (n & i)
		{
			if (i == 0x100 || i == 0x020 || i == 0x004)
				ft_putchar('r');
			if (i == 0x080 || i == 0x010 || i == 0x002)
				ft_putchar('w');
			if (i == 0x040 || i == 0x008 || i == 0x001)
				ft_putchar('x');
		}
		else
			ft_putchar('-');
		i >>= 1;
	}
}

void ft_optl(struct dirent *read, t_options options, char *av)
{
	struct stat stats;
	char *tmp;

	if (read->d_type == 4)
		ft_putchar('d');
	else if (read->d_type == 8)
		ft_putchar('-');
	else if (read->d_type == 10)
		ft_putchar('l');
	else
		ft_putnbr(read->d_type);
	tmp = ft_strjoin(av, "/");
	stat(ft_strjoin(tmp, read->d_name), &stats);
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
}

void	ft_ls(t_options options, char *av)
{
	DIR 	*dir;
	struct dirent 	*read;
	int 			flag;
	char			*path;

	dir = opendir(av);
	flag = 0;
	while ((read = readdir(dir)))
	{
		if ((read->d_name[0] == '.' && options.a == 1)
			|| options.a == 1 || (options.a == 0 && read->d_name[0] != '.'))
		{
			if (options.l)
			{
				ft_optl(read, options, av);
				ft_putchar('\t');
			}
			ft_putstr(read->d_name);
			ft_putchar('\t');
			if (options.l)
				ft_putchar('\n');
			if (options.R && read->d_type == 4 && 
				   !(read->d_name[0] == '.' && read->d_name[1] == '\0')
				&& !(read->d_name[0] == '.' && read->d_name[1] == '.' && read->d_name[2] == '\0'))
				flag = 1;
			//ft_putchar('\t');
		}	
	}
//	closedir(dir);
	ft_putchar('\n');
	if (flag)
		{
			closedir(dir);
			dir = opendir(av);
		while ((read = readdir(dir)))
		{
			if (read->d_type == 4
				&& (read->d_name[0] != '.' && read->d_name[0] != '\0')
				&& !(read->d_name[0] == '.' && read->d_name[1] == '.' && read->d_name[2] == '\0'))
			{
				path = ft_strjoin(ft_strjoin(av, "/"), read->d_name);
				ft_putstr(path);
				ft_putchar('\n');
				ft_ls(options, path);
			}
		}
	}
	closedir(dir);
}

int main(int ac, char **av)
{

	t_options options;
	int i;

	options = create_struct();
	i = get_options(av, &options);
	if (i == ac)
	{
		ft_ls(options, ".");
	}
	while (av[i])
	{
		ft_ls(options, av[i]);
		i++;
	}
	return (0);
}