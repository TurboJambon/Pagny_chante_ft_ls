/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:03:37 by niragne           #+#    #+#             */
/*   Updated: 2017/01/16 01:48:29 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_getvector(t_point *a, t_point *b)
{
	t_vector	*v;
	int			x;
	int			y;
	int			z;

	x = b->x - a->x;
	y = b->y - a->y;
	z = b->z - a->z;
	v = ft_newvector(x, y, z);
	if (!v)
		return (NULL);
	return (v);
}
