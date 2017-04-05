/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 18:50:37 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/05 19:57:12 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void 		ft_mode(mode_t n)
{
	mode_t 	i;

	i = 0x100;
	while (i > 0)
	{
		if (n & i)
		{
			if (i & 0x124)
				ft_putchar('r');
			else if (i & 0x092)
				ft_putchar('w');
			else if (i & 0x049)
				ft_putchar('x');
		}
		else
			ft_putchar('-');
		i >>= 1;
	}
}