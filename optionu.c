/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optionu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:38:45 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/05 17:03:41 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_dir		*ft_optionu(t_dir *folder, char *path, int a, int len)
{
	struct stat		stats;
	int				i;
	char			*str;

	i = 0;
	while (folder[i].type)
	{
		if ((folder[i].name[0] == '.' && a)
			|| a
			|| (a == 0 && folder[i].name[0] != '.'))
		{
			str = ft_strjoinspe(path, folder[i].name);
			lstat(str, &stats);
			folder[i].time = stats.st_atime;
			free(str);
		}
		i++;
	}
	return (ft_tsort(folder, len));
}