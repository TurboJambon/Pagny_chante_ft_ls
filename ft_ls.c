/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:00:10 by dchirol           #+#    #+#             */
/*   Updated: 2017/03/28 18:34:27 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\e[1;96m"
#define WHT   "\x1B[37m"
#define RESET "\e[0m"

#include "ls.h"

void	freedir(t_dir *tab)
{
	int i;

	i = 0;
	while (tab[i].type)
	{
		ft_strdel(&tab[i].name);
		i++;
	}
}

char	*ft_strjoinspe(char const *s1, char const *s2)
{
	size_t	i;
	int		j;
	char	*new;
	size_t	size;

	if (!s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	new = ft_strnew(size + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i < size)
		new[j++] = s1[i++];
	i = 0;
	new[j++] = '/';
	while (s2[i] && i < size)
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}

t_dir *ft_optiont(t_dir *folder, char *path, int a, int len)
{
	struct stat 	stats;
	int 			i;
	t_dir 			tmp;
	int				flag;
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

void	ft_putdate(char const *str)
{
	int 	i;
	char 	*ptr;
	char	*tmp;

	if (!str)
		return ;
	i = 4;
	tmp = ft_itoa(time(NULL) / 31536000 + 1970);
	if ((ptr = ft_strstr(str , tmp)))
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

void	ft_blocks(char *path, int a, t_dir *folder)
{
	struct stat stats;
	unsigned long blocks;
	int i;

	i = 0;
	blocks = 0;
	if (!folder[i].type)
		return;
	while (folder[i].type)
	{
		if ((folder[i].name[0] == '.' && a)
			|| a 
			|| (a == 0 && folder[i].name[0] != '.'))
		{
			if (folder[i].type == 10)
				lstat(ft_strjoinspe(path, folder[i].name), &stats);
			else
				stat(ft_strjoinspe(path, folder[i].name), &stats);
			blocks += stats.st_blocks;
		}
		i++;
	}
	ft_putstr("total ");
	ft_putnbr(blocks);
	ft_putchar('\n');
}

int	ft_dirlen(DIR *dir, t_options options)
{
	struct dirent *read;
	int i;

	i = 0;
	while ((read = readdir(dir)))
	{
		if ((read->d_name[0] == '.' && options.a == 1)
			|| options.a == 1 || (options.a == 0 && read->d_name[0] != '.'))
		i++; 
	}
	closedir(dir);
	return (i);
}

t_dir	*ft_folder(t_options options, char *path, int len)
{
	DIR 			*dir;
	struct dirent	*read;
	t_dir			*ret;
	struct stat 	stats;
	int				i;

	i = 0;
	dir = opendir(path);
	ret = malloc(sizeof(t_dir) * len + 1);
	while ((read = readdir(dir)))
	{
		if ((read->d_name[0] == '.' && options.a == 1)
			|| options.a == 1 || (options.a == 0 && read->d_name[0] != '.'))
		{
			stat(read->d_name, &stats);
			ret[i].type = read->d_type;
			ret[i].name = ft_strdup(read->d_name);
			ret[i].mode = stats.st_mode;
			i++;
		}
	}
	ret[len].type = 0;
	closedir(dir);
	free(read);
	return (ret);
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

void ft_optl(t_dir folder, char *av)
{
	struct stat stats;
	char	*str;

	if (folder.type == 4)
		ft_putchar('d');
	else if (folder.type == 8)
		ft_putchar('-');
	else if (folder.type == 10)
		ft_putchar('l');
	else
		ft_putnbr(folder.type);
	str = ft_strjoinspe(av, folder.name);
	if (folder.type == 10)
		lstat(str, &stats);
	else
		stat(str, &stats);
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

t_dir	*ft_sort_dirname(t_dir *folder, size_t len)
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


void 	ft_ls(t_options options, char *av)
{
	DIR 				*dir;
	t_dir 				*folder;
	int 				i;
	int 				len;
	int 				flag;
	char 				*path;

	path = NULL;
	i = 0;
	dir = opendir(av);
	len = ft_dirlen(dir, options);
	//closedir(dir);
	folder = ft_folder(options, av, len);
	folder = ft_sort_dirname(folder, len);
//	ft_print(folder, options, len, av);
	flag = 0;
	i = 0;
	if (options.l)
		ft_blocks(av, options.a, folder);
	if (options.t)
		folder = ft_optiont(folder, av, options.a, len);
	if (!options.r)
	{
		while (folder[i].type)
		{
			if (folder[i].type == 4 && options.R)
				flag = 1;
			if (options.l)
			{
				ft_optl(folder[i], av);
				ft_putchar('\t');
				if (folder[i].type == 4)
					ft_putstr(CYN);
				else if (folder[i].type == 10)
					ft_putstr(MAG);
				else if (folder[i].mode == 33261)
					ft_putstr(RED);
				ft_putstr(folder[i].name);
				ft_putchar('\n');
				ft_putstr(RESET);
			}
			else
			{
				if (folder[i].type == 4)
					ft_putstr(CYN);
				else if (folder[i].type == 10)
					ft_putstr(MAG);
				else if (folder[i].mode == 33261)
					ft_putstr(RED);
				ft_putstr(folder[i].name);
				ft_putchar('\t');
				ft_putstr(RESET);
			}
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			if (folder[i].type == 4 && options.R)
				flag = 1;
			if (options.l)
			{
				ft_optl(folder[i], av);
				if (folder[i].type == 4)
					ft_putstr(CYN);
				else if (folder[i].type == 10)
					ft_putstr(MAG);
				else if (folder[i].mode == 33261)
					ft_putstr(RED);
				ft_putchar('\t');
				ft_putstr(folder[i].name);
				ft_putchar('\n');
				ft_putstr(RESET);
			}
			else
			{
				if (folder[i].type == 4)
					ft_putstr(CYN);
				else if (folder[i].type == 10)
					ft_putstr(MAG);
				else if (folder[i].mode == 33261)
					ft_putstr(RED);
				ft_putstr(folder[i].name);
				ft_putchar('\t');
				ft_putstr(RESET);
			}
			i--;
		}
	}
	ft_putchar('\n');
	i = 0;
	if (flag)
	{
		if (!options.r)
		{
			while (folder[i].type)
			{
				if (folder[i].type == 4
					&& (folder[i].name[0] != '.' && folder[i].name[0] != '\0')
					&& !(folder[i].name[0] == '.' && folder[i].name[1] == '.' && folder[i].name[2] == '\0'))
				{
					path = ft_strjoinspe(av, folder[i].name);
					ft_putstr(path);
					ft_putstr(":\n");
					ft_ls(options, path);
				}
				i++;
			}
		}
		else if(options.r)
		{
			i = len - 1;
			while (i >= 0)
			{
				if (folder[i].type == 4
					&& (folder[i].name[0] != '.' && folder[i].name[0] != '\0')
					&& !(folder[i].name[0] == '.' && folder[i].name[1] == '.' && folder[i].name[2] == '\0'))
				{
					path = ft_strjoinspe(av, folder[i].name);
					ft_putstr(path);
					ft_putstr(":\n");
					ft_ls(options, path);
				}
			i--;
			}
		}
	}
	free(path);
	freedir(folder);
	free(folder);
}



int main(int ac, char **av)
{  

	t_options options;
	int i;
	int flag;

	flag = 0;
	options = create_struct();
	i = get_options(av, &options);
	if (i == ac)
	{
		ft_ls(options, ".");
	}
	if (i < 1)
		flag = 1;
	while (av[i])
	{
		ft_ls(options, av[i]);
		i++;
	}
	while (1);
	return (0);
}