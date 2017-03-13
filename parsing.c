/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David <David@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:21:52 by David             #+#    #+#             */
/*   Updated: 2017/03/13 18:20:30 by David            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_options create_struct()
{
	t_options ret;

	ret.R = 0;
	ret.a = 0;
	ret.r = 0;
	ret.l = 0;
	ret.t = 0;
	return (ret);
}

int		add_option(char c, t_options *options)
{
	if (c == 'R')
		return(options->R = 1);
	if (c == 'a')
		return(options->a = 1);
	if (c == 'r')
		return(options->r = 1);
	if (c == 'l')
		return(options->l = 1);
	if (c == 't')
		return(options->t = 1);
	return (-1);
}

int get_options(char **av, t_options *options)
{
	int i;
	int j;
	int flag;

	i = 1;
	flag = 0;
	while (av[i])
	{
		j = 1;
		if (av[i][0] != '-')
			break;
		else
		{
			while (av[i][j])
			{
				printf("cul\n");
				printf("%c\n", av[i][j]);
				if (add_option(av[i][j], options) == -1)
				{
					ft_putstr("t con");
					return (-1);
				}
				printf("bite\n");
				j++;
			}
		}
		i++;
	}
	return (0);
}