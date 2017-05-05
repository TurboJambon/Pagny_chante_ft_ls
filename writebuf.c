/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writebuf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:18:14 by niragne           #+#    #+#             */
/*   Updated: 2017/05/05 18:15:08 by dchirol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_putstr_buf(char *str)
{
	size_t len;

	len = ft_strlen(str);
	ft_buf(1, str, len);
}

void	ft_putstr_buf_fd(char *str, int fd)
{
	size_t len;

	len = ft_strlen(str);
	ft_buf(fd, str, len);
}

void	ft_putchar_buf(char c)
{
	ft_buf(1, &c, 1);
}

void	ft_putchar_buf_fd(char c, int fd)
{
	ft_buf(fd, &c, 1);
}

void	ft_putcharendl_buf_fd(char c, int fd)
{
	ft_buf(fd, &c, 1);
	ft_putchar_buf_fd('\n', fd);
}
