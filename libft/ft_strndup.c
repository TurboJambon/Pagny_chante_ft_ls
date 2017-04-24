/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:07:46 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/24 14:08:42 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strndup(char const *s1, int n)
{
	char		*new;
	size_t		i;

	i = 0;
	if ((new = ft_strnew(ft_strlen(s1))))
	{
		while (i < (size_t)n)
		{
			new[i] = s1[i];
			i++;
		}
	}
	return (new);
}
