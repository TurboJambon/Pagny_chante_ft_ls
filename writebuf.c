/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writebuf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:18:14 by niragne           #+#    #+#             */
/*   Updated: 2017/04/21 17:57:55 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_putstr_buf(char *str)
{
	size_t len;

	len = ft_strlen(str);
	ft_buf(1, str, len);
}

void	ft_putchar_buf(char c)
{
	ft_buf(1, &c, 1);
}

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