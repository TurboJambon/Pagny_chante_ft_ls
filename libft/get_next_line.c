/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 18:28:56 by niragne           #+#    #+#             */
/*   Updated: 2017/02/02 22:47:17 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_strjoin_free(char const *s1, char const *s2)
{
	size_t	i;
	int		j;
	char	*new;
	size_t	size;

	if (!s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	new = ft_strnew(size);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i < size)
		new[j++] = s1[i++];
	i = 0;
	while (s2[i] && i < size)
		new[j++] = s2[i++];
	new[j] = '\0';
	ft_strdel((char**)&s1);
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	static char		*stock[OPEN_MAX];
	t_gnl			gnl;

	gnl.rd = 1;
	if (fd < 0)
		return (-1);
	if (stock[fd] == NULL)
		stock[fd] = ft_strnew(0);
	while (gnl.rd != -1)
	{
		if ((gnl.tmp = ft_strchr(stock[fd], '\n')) ||
			((gnl.tmp = ft_strchr(stock[fd], '\0')) && !gnl.rd))
		{
			*(gnl.tmp) = '\0';
			*line = ft_strdup(stock[fd]);
			ft_memmove(stock[fd], gnl.tmp + 1, ft_strlen(gnl.tmp + 1) + 1);
			return ((line[0][0] || (!line[0][0] && gnl.rd)));
		}
		if ((gnl.rd = read(fd, gnl.buf, BUFF_SIZE)) == -1)
			return (-1);
		gnl.buf[gnl.rd] = '\0';
		stock[fd] = ft_strjoin_free(stock[fd], gnl.buf);
	}
	return (-1);
}
