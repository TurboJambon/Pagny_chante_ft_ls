/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:28:00 by niragne           #+#    #+#             */
/*   Updated: 2016/12/02 16:28:04 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rot(char *str, int r)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_strnew(ft_strlen(str));
	while (str[i])
	{
		if (ft_isupper(str[i]))
		{
			new[i] = (((str[i] - 65) + r) % 26) + 65;
			if (new[i] < 0)
				new[i] += 26;
		}
		else if (ft_islower(str[i]))
		{
			new[i] = (((str[i] - 97) + r) % 26) + 97;
			if (new[i] < 0)
				new[i] += 26;
		}
		else
			new[i] = str[i];
		i++;
	}
	return (new);
}
