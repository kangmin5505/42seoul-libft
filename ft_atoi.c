/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:58:58 by kangkim           #+#    #+#             */
/*   Updated: 2021/11/16 16:02:17 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int			n;
	int			neg;
	const char	*s;

	n = 0;
	neg = -1;
	s = nptr;
	while (ft_isspace(*s))
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		neg = 1;
		s++;
	}
	while (ft_isdigit(*s))
		n = 10 * n - (*s++ - '0');
	return (neg * n);
}
