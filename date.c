/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 15:53:25 by niragne           #+#    #+#             */
/*   Updated: 2017/04/24 14:29:42 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void			ft_color(int type, mode_t mode)
{
	if (type == 4)
		ft_putstr_buf(CYN);
	else if (type == 10)
		ft_putstr_buf(MAG);
	else if (mode & 0x049)
		ft_putstr_buf(RED);
}

static void		putyear(time_t date)
{
	char		*str;
	int			i;

	i = 3;
	str = ctime(&date);
	while (i <= 9)
	{
		ft_putchar_buf(str[i]);
		i++;
	}
	ft_putchar_buf(' ');
	ft_buf(1, str + 20, 4);
}

static void		putdatejambon(time_t date)
{
	int		i;
	char	*str;

	str = ctime(&date);
	i = 4;
	ft_putchar_buf(' ');
	while (i <= 15)
	{
		ft_putchar_buf(str[i]);
		i++;
	}
}

void			ft_putdate(time_t date)
{
	if (time(NULL) - date > 15768000)
		putyear(date);
	else
		putdatejambon(date);
}
