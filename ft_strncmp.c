/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:35:53 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/22 14:55:44 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			idx;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	idx = 0;
	while (n--)
	{
		if (ptr1[idx] != ptr2[idx] || ptr1[idx] == 0 || ptr2[idx] == 0)
			return ((int)(ptr1[idx] - ptr2[idx]));
		idx++;
	}
	return (0);
}
