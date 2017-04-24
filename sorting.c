/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:26:34 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/24 14:44:11 by dchirol          ###   ########.fr       */
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

char	**ft_sort_av(char **av, int i)
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

char	**ft_sort_spe(char **tab, int j)
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
