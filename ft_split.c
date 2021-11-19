/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:07:34 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/19 15:40:23 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_delimiter(char c, char delimiter)
{
	return (c == delimiter);
}

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
				break ;
		}
		idx++;
	}
	return (word_cnt);
}

static char	**ft_malloc_error(char **strs)
{
	size_t	idx;

	idx = 0;
	while (strs[idx])
		free(strs[idx++]);
	free(strs);
	return (NULL);
}

static char	**ft_get_strs(char **strs, char const *s, size_t word_cnt, char c)
{
	size_t	strs_idx;
	size_t	s_idx;
	size_t	temp;

	strs_idx = 0;
	s_idx = 0;
	while (strs_idx < word_cnt)
	{
		if (ft_is_delimiter(s[s_idx], c) != 1)
		{
			temp = s_idx;
			while (s[s_idx] && (ft_is_delimiter(s[s_idx], c) != 1))
				s_idx++;
			strs[strs_idx] = (char *)malloc(sizeof(char) * (s_idx - temp + 1));
			if (!strs[strs_idx])
				return (ft_malloc_error(strs));
			ft_strlcpy(strs[strs_idx], s + temp, s_idx - temp + 1);
			strs_idx++;
		}
		s_idx++;
	}
	strs[strs_idx] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	word_cnt;

	if (!s)
		return (NULL);
	word_cnt = ft_get_word_cnt(s, c);
	strs = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!strs)
		return (NULL);
	strs = ft_get_strs(strs, s, word_cnt, c);
	if (!strs)
		return (NULL);
	return (strs);
}
