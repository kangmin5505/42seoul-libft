/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:40:45 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/18 15:48:08 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_screen(long long nbr, int fd)
{
	char	c;

	if (nbr >= 10)
		ft_print_screen(nbr / 10, fd);
	c = nbr % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	nbr;

	nbr = (long long)n;
	if (fd >= 0)
	{
		if (nbr < 0)
		{
			nbr *= -1;
			write(fd, "-", 1);
		}
		ft_print_screen(nbr, fd);
	}
}
