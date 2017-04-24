/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:53:10 by niragne           #+#    #+#             */
/*   Updated: 2016/11/12 18:53:13 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_get_int_size(int n)
{
	int ret;

	if (n < 0)
	{
		ret = 3;
		n = -n;
	}
	else
		ret = 2;
	while (n /= 10)
		ret++;
	return (ret);
}

char			*ft_itoa(int n)
{
	char	*ret;
	size_t	size;
	int		sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	size = ft_get_int_size(n);
	if ((ret = (char *)malloc(sizeof(char) * size--)) == NULL)
		return (NULL);
	ret[size--] = '\0';
	ret[size--] = sign * (n % 10) + '0';
	while ((n /= 10))
		ret[size--] = sign * (n % 10) + '0';
	if (sign < 0)
		ret[size] = '-';
	return (ret);
}
