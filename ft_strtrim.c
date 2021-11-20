/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:32:31 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/20 15:32:09 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_start_idx(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	idx;

	s1_len = ft_strlen(s1);
	idx = 0;
	while (idx < s1_len)
	{
		if (ft_strchr(set, s1[idx]) == 0)
			break ;
		idx++;
	}
	return (idx);
}

static size_t	ft_get_end_idx(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	idx;

	s1_len = ft_strlen(s1);
	idx = 0;
	while (idx < s1_len)
	{
		if (ft_strchr(set, s1[s1_len - idx - 1]) == 0)
			break ;
		idx++;
	}
	return (s1_len - idx);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret_str;
	size_t	start_idx;
	size_t	end_idx;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	start_idx = ft_get_start_idx(s1, set);
	end_idx = ft_get_end_idx(s1, set);
	if (start_idx >= end_idx)
		return (ft_strdup(""));
	ret_str = (char *)malloc(sizeof(char) * (end_idx - start_idx + 1));
	if (!ret_str)
		return (NULL);
	ft_strlcpy(ret_str, s1 + start_idx, end_idx - start_idx + 1);
	return (ret_str);
}
