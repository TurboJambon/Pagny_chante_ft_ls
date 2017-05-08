/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 23:46:10 by niragne           #+#    #+#             */
/*   Updated: 2017/05/08 15:36:36 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ls.h"

void	printerr(char *arg, int err, int flaf)
{
	if (err == 2)
	{
		ft_putstr_buf("ls: ");
		ft_putstr_buf(arg);
		ft_putstr_buf(": No such file or directory\n\n");
	}
	else if (err == 20 && !flaf)
	{
		ft_putstr_buf(arg);
		ft_putchar_buf('\t');
	}
	else if (err == 13)
	{
		ft_putstr_buf("ls: ");
		ft_putstr_buf(arg);
		ft_putstr_buf(": Permission denied\n\n");
	}
}
