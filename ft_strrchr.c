/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:32:12 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/16 15:35:34 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			s_len;
	char		find;
	const char	*ret;

	s_len = ft_strlen(s);
	find = (char)c;
	ret = &s[s_len];
	while (s_len)
	{
		if (ret[s_len] == find)
			return (&ret[s_len]);
		s_len--;
	}
	if (ret[s_len] == find)
		return (&ret[s_len]);
	return (0);
}
