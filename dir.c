/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:33:13 by dchirol           #+#    #+#             */
/*   Updated: 2017/03/22 18:12:54 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_putdate(char const *str)
{
	int 	i;
	char 	*ptr;

	if (!str)
		return ;
	i = 4;
	if ((ptr = ft_strstr(str , ft_itoa(time(NULL) / 31536000 + 1970))))
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
}

void ft_mode(mode_t n)
{
	mode_t 	i;

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
	char 		*tmp;

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

void	ft_printblocks(int a, char *path)
{
	DIR *dir;
	struct dirent *read;
	struct stat stats;
	unsigned long blocks;

	blocks = 0;
	dir = opendir(path);
	while((read = readdir(dir)))
	{
		if ((read->d_name[0] == '.' && a)
			|| a 
			|| (a == 0 && read->d_name[0] != '.'))
		{
			stat(ft_strjoin(path, read->d_name), &stats);
			blocks += stats.st_blocks;
		}
	}
	ft_putstr("total ");
	ft_putnbr(blocks);
	ft_putchar('\n');
	closedir(dir);
}

t_stock setstock(time_t time, char *name)
{
	t_stock ret;

	ret.time = time;
	ret.name = ft_strdup(name);
	//printf("name : %s-- retname : %s -- \n", name, ret.name);
	return (ret);
}

int		ft_strcmp_ascii(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

t_stock	*ft_sort_stockname(t_stock *stock, size_t len)
{
	char 	*tmp;
	int		flag;
	size_t	i;

	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i <= len)
		{
			printf("%d\n", i);
			if (ft_strcmp_ascii(stock[i].name, stock[i + 1].name) > 0)
			{
				tmp = ft_strdup(stock[i].name);
				printf("%s\n", stock[i].name);
				stock[i].name = stock[i + 1].name;
				stock[i + 1].name = tmp;
				flag = 1;
			}
			i++;
		}
	}
	return (stock);
}

t_stock	*ft_sort_stocktime(t_stock *stock, size_t len)
{
	int		tmp;
	int		flag;
	size_t	i;

	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i <= len)
		{
			if (stock[i].time > stock[i + 1].time)
			{
				tmp = stock[i].time;
				stock[i].time = stock[i + 1].time;
				stock[i + 1].time = tmp;
				flag = 1;
			}
			i++;
		}
	}
	return (stock);
}

int	ft_dirlen(DIR *dir)
{
	struct dirent *read;
	int i;

	i = 0;
	while ((read = readdir(dir)))
		i++; 
	closedir(dir);
	return (i);
}

void	ft_optiont(DIR *dir, t_options options, char *av)
{
	struct dirent 	*read;
	struct stat		stats;
	t_stock	*stock;
	int i;
	int flag;
	int len;

	i = 0;
	dir = opendir(av);
	len = ft_dirlen(dir);
	stock = malloc(sizeof(t_stock) * len);
	dir = opendir(av);
	while ((read = readdir(dir)))
	{
		stat(ft_strjoin(ft_strjoin(av, "/"), read->d_name), &stats);
		stock[i] = setstock(stats.st_mtime, read->d_name);
		i++;
	}
	stock = ft_sort_stockname(stock, len);
	while (i != 0)
	{
		if ((stock[i].name[0] == '.' && options.a == 1)
			|| options.a == 1 || (options.a == 0 && stock[i].name[0] != '.'))
		{
			if (options.l)
			{
				ft_optl(read, options, av); 
				ft_putchar('\t');
			}
			ft_putstr(stock[i].name);
			ft_putchar('\t');
			if (options.l)
				ft_putchar('\n');
		}	
		i--;
	}
}

void	ft_ls(t_options options, char *av)
{
	DIR 			*dir;
	struct dirent 	*read;
	int 			flag;
	char			*path;
	struct stat 	stats;

	dir = opendir(av);
	if (options.t)
	{
		ft_optiont(dir, options, av);
		exit(0);
	}
	if (options.l)
		ft_printblocks(options.a, ft_strjoin(av, "/"));
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
		}	
	}
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
{  //acab

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