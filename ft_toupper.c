/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:24:59 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/16 15:28:33 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_islower(int c)
{
	return ((unsigned)c - 'a' < 26);
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c & 0x5f);
	return (c);
}
