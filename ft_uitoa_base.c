/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:39:46 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/06 16:59:58 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_int_len(unsigned int nbr, int base)
{
	unsigned int	len;

	if (nbr == 0 || base == 0)
		return (1);
	len = 0;
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char	*ft_uitoa_base(unsigned int n, int base)
{
	unsigned int	nbr;
	unsigned int	len;
	char			*str;

	nbr = n;
	len = ft_int_len(nbr, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = "0123456789abcdef"[nbr % base];
		nbr /= base;
	}
	return (str);
}
