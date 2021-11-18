/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:32:07 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/18 15:36:21 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	idx;

	if (s && f)
	{
		idx = 0;
		while (s[idx])
		{
			(*f)(idx, &s[idx]);
			idx++;
		}
		s[idx] = '\0';
	}
}
