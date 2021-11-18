/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:52:28 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/18 21:01:05 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s_len;
	char	*mem;
	size_t	idx;

	s_len = ft_strlen(s1);
	mem = (char *)malloc((s_len + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		mem[idx] = s1[idx];
		idx++;
	}
	mem[idx] = '\0';
	return (mem);
}
