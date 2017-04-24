/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_middle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:32:42 by niragne           #+#    #+#             */
/*   Updated: 2017/01/16 03:59:50 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_point		ft_get_middle(t_point a, t_point b)
{
	t_point middle;
	int		x;
	int		y;
	int		z;

	x = (a.x + b.x) / 2;
	y = (a.y + b.y) / 2;
	z = (a.z + b.z) / 2;
	middle = ft_newpoint(x, y, z);
	return (middle);
}
