/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:58:58 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/23 15:48:52 by kangkim          ###   ########.fr       */
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
	int			sign;
	long long	ll_check;

	n = 0;
	sign = 1;
	ll_check = LLONG_MAX / 10;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		if (sign == 1 && (n > ll_check || (n == ll_check && *nptr - '0' >= 7)))
			return (-1);
		if (sign == -1 && (n > ll_check || (n == ll_check && *nptr - '0' >= 8)))
			return (0);
		n = 10 * n + (*nptr++ - '0');
	}
	return (sign * (int)n);
}
