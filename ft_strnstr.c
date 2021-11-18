/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:48:50 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/18 20:42:14 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t		substr_len;
	size_t		str_len;
	const char	*s;

	if (*substr == '\0')
		return ((char *)str);
	substr_len = ft_strlen(substr);
	str_len = ft_strlen(str);
	if (str_len < substr_len || len < substr_len)
		return (NULL);
	s = (const char *)str;
	while (*s && substr_len <= len--)
	{
		if (ft_memcmp(s, substr, substr_len) == 0)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
