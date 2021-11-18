/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:41:53 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/18 20:43:45 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char	*s;

	s = (const unsigned char *)src;
	c = (unsigned char)c;
	while (n--)
	{
		if (*s == c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
