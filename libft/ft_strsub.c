/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:34:48 by niragne           #+#    #+#             */
/*   Updated: 2016/11/15 19:34:49 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	new = ft_strnew(len);
	if (!s)
		return (NULL);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[i + start];
		i++;
	}
	return (new);
}
