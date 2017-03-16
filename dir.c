/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:33:13 by dchirol           #+#    #+#             */
/*   Updated: 2017/03/16 15:14:29 by dchirol          ###   ########.fr       */
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

void	ft_optionL(DIR *dir)
{
	struct dirent 	*read;
	struct stat stats;
	struct passwd *psw;

	while ((read = readdir(dir)))
	{
		stat(read->d_name, &stats);
		if (read->d_type == 4)
			ft_putchar('d');
		else if (read->d_type == 8)
			ft_putchar('-');
		else if (read->d_type == 10)
			ft_putchar('l');
		else
			ft_putnbr(read->d_type);
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
		ft_putstr("\t");
		//ft_putnbr(stats.st_mtime);
		//ft_putstr(" ");
		ft_putstr(read->d_name);
		ft_putchar('\n');
	}
	//closedir(dir);
}

int main(int ac, char **av)
{
	DIR 	*dir;
	struct dirent 	*read;
	t_options options;

	options = create_struct();
	get_options(av, &options);
	add_option('R', &options);
	printf("R %d\n", options.R);
	printf("r %d\n", options.r);
	printf("t %d\n", options.t);
	printf("l %d\n", options.l);
	printf("a %d\n", options.a);
	printf("PARSING OK\n");
	if (!av[1])
		dir = opendir(".");
	else 
		dir = opendir(av[1]);
	ft_optionL(dir);
	while ((read = readdir(dir)))
	{
		if (!(read->d_name[0] == '.'))
		{
			ft_putstr(read->d_name);
			ft_putchar('\t');
		}
	}
	ft_putchar('\n');
	closedir(dir);
	return (0);
}