/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:25:38 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/16 15:28:18 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isupper(int c)
{
	return ((unsigned)c - 'A' < 26);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c | 32);
	return (c);
}
