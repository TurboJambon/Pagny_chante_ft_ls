/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 18:37:16 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/09 15:02:46 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		freedir(t_dir *tab)
{
	int i;

	i = 0;
	while (tab[i].type)
	{
		ft_strdel(&tab[i].name);
		i++;
	}
}

char		*ft_strjoinspe(char const *s1, char const *s2)
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

int			ft_dirlen(DIR *dir, t_options options)
{
	struct dirent	*read;
	int				i;

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

t_dir		*ft_folder(t_options options, char *path, int len)
{
	DIR				*dir;
	struct dirent	*read;
	t_dir			*ret;
	struct stat		stats;
	char			*megapath;

	options.i = 0;
	dir = opendir(path);
	ret = malloc(sizeof(t_dir) * len + 1);
	while ((read = readdir(dir)))
	{
		if ((read->d_name[0] == '.' && options.a == 1)
			|| options.a == 1 || (options.a == 0 && read->d_name[0] != '.'))
		{
			ret[options.i].type = read->d_type;
			megapath = ft_strjoinspe(path, read->d_name);
			(read->d_type == 10) ? lstat(megapath, &stats) : stat(megapath, &stats);
			ret[options.i].name = ft_strdup(read->d_name);
			ret[options.i].mode = stats.st_mode;
			free(megapath);
			options.i++;
		}
	}
	ret[len].type = 0;
	closedir(dir);
	free(read);
	return (ret);
}
