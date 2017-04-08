/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 22:51:03 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/08 23:16:05 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		ft_putdate(char const *str)
{
	int		i;
	char	*ptr;
	char	*tmp;

	if (!str)
		return ;
	i = 4;
	tmp = ft_itoa(time(NULL) / 31536000 + 1970);
	if ((ptr = ft_strstr(str, tmp)))
		write(1, str + 3, ptr - str - 7);
	else
	{
		ft_putchar(' ');
		while (str[i] != '\n')
		{
			if (i >= 10 && 18 >= i)
				i++;
			else
			{
				ft_putchar(str[i]);
				i++;
			}
		}
	}
	free(tmp);
}

