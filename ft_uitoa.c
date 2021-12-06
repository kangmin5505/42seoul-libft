/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:39:22 by kangkim           #+#    #+#             */
/*   Updated: 2021/12/06 14:42:32 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_int_len(unsigned int nbr)
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

char	*ft_uitoa(unsigned int n)
{
	unsigned int	nbr;
	unsigned int	len;
	char			*str;

	nbr = n;
	len = ft_int_len(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (str);
}
