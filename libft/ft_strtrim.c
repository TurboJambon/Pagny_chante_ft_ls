/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:10:06 by niragne           #+#    #+#             */
/*   Updated: 2016/11/20 15:10:07 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_isspace_trim(int c)
{
	if (c == '\n' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

static	int		ft_is_only_space(char const *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isspace_trim(s[i])))
			return (0);
		i++;
	}
	return (1);
}

static	int		ft_get_beginning(char const *s)
{
	int	i;

	i = 0;
	while (ft_isspace_trim(s[i]))
	{
		i++;
	}
	return (i);
}

static	int		ft_get_end(char const *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (ft_isspace_trim(s[i]))
		i--;
	return (i + 1);
}

char			*ft_strtrim(char const *s)
{
	char	*ret;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (ft_is_only_space(s))
		return (ft_strdup(""));
	ret = ft_strnew(ft_get_end(s) - ft_get_beginning(s));
	i = ft_get_beginning(s);
	j = 0;
	if (!ret)
		return (NULL);
	while (i < ft_get_end(s))
	{
		ret[j++] = s[i++];
	}
	ret[i] = '\0';
	return (ret);
}
