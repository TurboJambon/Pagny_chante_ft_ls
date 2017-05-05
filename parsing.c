/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 22:00:14 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/05 17:46:31 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_options	create_struct(void)
{
	t_options ret;

	ret.r2 = 0;
	ret.a = 0;
	ret.r = 0;
	ret.l = 0;
	ret.t = 0;
	ret.u = 0;
	ret.f = 0;
	ret.g = 0;
	return (ret);
}

int			add_option(char c, t_options *options)
{
	if (c == 'R')
		return (options->r2 = 1);
	if (c == 'a')
		return (options->a = 1);
	if (c == 'r')
		return (options->r = 1);
	if (c == 'l')
		return (options->l = 1);
	if (c == 't')
		return (options->t = 1);
	if (c == 'p')
		return (options->p = 1);
	if (c == 'u')
		return (options->u = 1);
	if (c == 'f')
		return ((options->f = 1) && (options->a = 1));
	if (c == 'g')
		return ((options->g = 1) && (options->l = 1));
	return (-1);
}

int			puterr(char *s)
{
	ft_putendl_buf_fd(s, 2);
	ft_buf(1, NULL, -1);
	return (-1);
}

int			get_options(char **av, t_options *options)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][0] != '-')
			break ;
		else
		{
			while (av[i][++j])
			{
				if (add_option(av[i][j], options) == -1)
				{
					ft_putstr_buf_fd("ls: illegal option -- ", 2);
					ft_putendl_buf_fd(&av[i][j], 1);
					return (puterr(""));
				}
			}
		}
	}
	return (i);
}

void		del_options(t_options *options)
{
	options->r = 0;
	options->t = 0;
}