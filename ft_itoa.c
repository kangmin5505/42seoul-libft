/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:13:52 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/18 16:56:29 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_int_len(long long nbr)
{
	unsigned int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long		nbr;
	unsigned int	len;
	char			*str;

	nbr = (long long)n;
	if (n < 0)
		nbr *= -1;
	len = ft_int_len(nbr);
	if (n < 0)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = '0' + (nbr % 10);
		nbr /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
