/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 22:00:14 by dchirol           #+#    #+#             */
/*   Updated: 2017/04/08 23:16:06 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_options	create_struct(void)
{
	t_options ret;

	ret.R = 0;
	ret.a = 0;
	ret.r = 0;
	ret.l = 0;
	ret.t = 0;
	return (ret);
}

int			add_option(char c, t_options *options)
{
	if (c == 'R')
		return (options->R = 1);
	if (c == 'a')
		return (options->a = 1);
	if (c == 'r')
		return (options->r = 1);
	if (c == 'l')
		return (options->l = 1);
	if (c == 't')
		return (options->t = 1);
	return (-1);
}

int			puterr(char *s)
{
	ft_putendl_fd(s, 2);
	return (-1);
}

int			get_options(char **av, t_options *options)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while (av[i])
	{
		j = 1;
		if (av[i][0] != '-')
			break ;
		else
		{
			while (av[i][j])
			{
				if (add_option(av[i][j], options) == -1)
				{
					return (puterr("illegal option"));
				}
				j++;
			}
		}
		i++;
	}
	return (i);
}
