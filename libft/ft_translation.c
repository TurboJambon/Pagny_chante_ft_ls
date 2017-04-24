/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:37:03 by niragne           #+#    #+#             */
/*   Updated: 2017/01/16 04:01:05 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_point		ft_translation(t_point p, t_vector v)
{
	t_point		new;
	int			x;
	int			y;
	int			z;

	x = p.x + v.x;
	y = p.y + v.y;
	z = p.z + v.z;
	new = ft_newpoint(x, y, z);
	return (new);
}
