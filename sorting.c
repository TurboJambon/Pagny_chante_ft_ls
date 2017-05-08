/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:26:34 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/08 18:00:35 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_dir	*ft_sort_dirname(t_dir *folder, size_t len)
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

int		swapparam(char **tab, char *sort)
{
	char *tmp;
	char tmpsort;

	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	tmpsort = sort[0];
	sort[0] = sort[1];
	sort[1] = tmpsort;
	return (1);
}

void	afftab(char **tab, int k)
{
	int i;

	i = 0;
	while (i < k)
	{
		printf(" - %s\n", tab[i]);
		i++;
	}
}

void	ft_sort_spe(char **tab, int ac, int k, t_options options)
{
	struct stat			stats;
	char				sort[ac - 1];
	int					i;
	int					flag;

	i = 0;
	while (i < ac - k)
	{
		lstat(tab[i], &stats);
		sort[i] = (stats.st_mode & S_IFDIR) > 0;
		i++;
	}
	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		if (!options.r)
		{
			while (i < ac - k - 1)
			{
				if (sort[i] > sort[i + 1] || (ft_strcmp(tab[i], tab[i + 1]) > 0
					&& sort[i] == sort[i + 1]))
					flag = swapparam(tab + i, sort + i);
				i++;
			}
		}
		if (options.r)
		{
			while (i < ac - k - 1)
			{
				if (sort[i] < sort[i + 1] || (ft_strcmp(tab[i], tab[i + 1]) < 0
					&& sort[i] == sort[i + 1]))
					flag = swapparam(tab + i, sort + i);
				i++;
			}
		}
	}
}
