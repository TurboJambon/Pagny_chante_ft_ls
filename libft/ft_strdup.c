/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:13:20 by niragne           #+#    #+#             */
/*   Updated: 2016/11/15 16:13:21 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char		*new;
	size_t		i;

	i = 0;
	if ((new = ft_strnew(ft_strlen(s1))))
	{
		while (i < ft_strlen(s1))
		{
			new[i] = s1[i];
			i++;
		}
	}
	return (new);
}
