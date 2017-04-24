/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 21:33:11 by niragne           #+#    #+#             */
/*   Updated: 2016/11/15 21:33:12 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] && (i < len))
	{
		j = i;
		k = 0;
		while (s1[j] == s2[k] && (j < len))
		{
			j++;
			k++;
			if (!s2[k])
				return ((char*)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
