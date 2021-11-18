/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:32:12 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/18 21:12:45 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		s_len;
	char		find;
	const char	*str;

	s_len = ft_strlen(s);
	find = (char)c;
	str = s;
	while (s_len)
	{
		if (str[s_len] == find)
			return ((char *)(str + s_len));
		s_len--;
	}
	if (str[s_len] == find)
		return ((char *)str);
	return (NULL);
}
