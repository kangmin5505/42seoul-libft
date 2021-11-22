/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:58:58 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/22 17:52:55 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || (unsigned)c - '\t' < 5);
}

int	ft_atoi(const char *nptr)
{
	long long	n;
	long long	neg;
	const char	*s;

	n = 0;
	neg = -1;
	s = nptr;
	while (ft_isspace(*s))
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		neg = 1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		if (n > 2147483647 && neg == -1)
			return (-1);
		if (n > 2147483648 && neg == 1)
			return (0);
		n = 10 * n - (*s++ - '0');
	}
	return ((int)(neg * n));
}
