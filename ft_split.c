/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:07:34 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/17 19:48:21 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static size_t	ft_get_word_cnt(char const *s, char c)
{
	size_t	word_cnt;
	size_t	idx;
	size_t	s_len;

	word_cnt = 0;
	idx = 0;
	s_len = ft_strlen(s);
	while (idx < s_len)
	{
		if (ft_is_delimiter(s[idx], c) != 1)
		{
			word_cnt++;
			idx++;
			while (s[idx] && (ft_is_delimiter(s[idx], c) != 1))
				idx++;
			if (!s[idx])
				idx--;
		}
		idx++;
	}
	return (word_cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	word_cnt;

	if (!s)
		return (NULL);
	word_cnt = ft_get_word_cnt(s, c);
}
