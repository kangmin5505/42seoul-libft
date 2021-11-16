/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:18:40 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/16 14:31:57 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				idx;
	unsigned char		*d;
	const unsigned char	*s;

	idx = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (idx++ < n)
		*d++ = *s++;
	return (dest);
}
