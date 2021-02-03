/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:52:33 by gkenzo-s          #+#    #+#             */
/*   Updated: 2021/01/22 15:39:42 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	convert_hex(int i)
{
	if (i == 10)
		return ('a');
	if (i == 11)
		return ('b');
	if (i == 12)
		return ('c');
	if (i == 13)
		return ('d');
	if (i == 14)
		return ('e');
	if (i == 15)
		return ('f');
	return (i + 48);
}

char		*ft_int_to_hex(long long n)
{
	char	*c;
	char	*str;
	size_t	uint_max;

	uint_max = 4294967295;
	c = ft_calloc(2, sizeof(char));
	str = ft_calloc(2, sizeof(char));
	if (n == 0)
	{
		*str = '0';
		return (str);
	}
	if (n < 0)
		n = uint_max + n + 1;
	while (n > 0)
	{
		c[0] = convert_hex(n % 16);
		str = ft_strjoin(c, str);
		n = n / 16;
	}
	return (str);
}
