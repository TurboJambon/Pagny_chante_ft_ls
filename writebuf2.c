/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writebuf2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:13:14 by dchirol           #+#    #+#             */
/*   Updated: 2017/05/05 18:13:39 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_putnbr_buf(int n)
{
	if (n == -2147483648)
		ft_putstr_buf("-2147483648");
	else if (!(n > 2147483647 || n < -2147483648))
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar_buf('-');
		}
		if (n >= 10)
		{
			ft_putnbr_buf(n / 10);
			ft_putnbr_buf(n % 10);
		}
		else
			ft_putchar_buf(n + '0');
	}
}

void	ft_putendl_buf_fd(char *str, int fd)
{
	size_t len;

	len = ft_strlen(str);
	ft_buf(fd, str, len);
	ft_buf(fd, "\n", 1);
}
