/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:18:04 by niragne           #+#    #+#             */
/*   Updated: 2016/11/15 17:18:05 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while (s[i] != s[0])
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i--;
	}
	if (s[i] == c)
		return ((char*)&s[i]);
	if (c == '\0')
		return ((char*)&s[ft_strlen(s) + 1]);
	return (NULL);
}
