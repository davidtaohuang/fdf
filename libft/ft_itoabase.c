/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 23:26:01 by dhuang            #+#    #+#             */
/*   Updated: 2016/10/24 10:51:51 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static int	ft_length(long n, int b)
{
	int		i;
	long	tens;

	i = 0;
	tens = 1;
	if (!n)
		i = 1;
	while (n >= tens)
	{
		tens *= b;
		i++;
	}
	return (i);
}

static void	ft_digits(char *a, long num, int i, int b)
{
	int		digits;
	int		c;
	long	tens;

	digits = ft_length(num, b);
	tens = 1;
	while (digits > 0)
	{
		tens *= b;
		digits--;
	}
	while (tens >= b)
	{
		tens /= b;
		c = num / tens;
		if (c < 10)
			a[i++] = (c + 48);
		else
			a[i++] = (c + 55);
		num -= (c * tens);
	}
	a[i] = '\0';
}

char		*ft_itoabase(int n, int b)
{
	int		len;
	int		i;
	long	num;
	char	*a;

	if (b <= 1)
		return (NULL);
	num = (long)n;
	if (num < 0)
		num *= -1;
	len = ft_length(num, b);
	if (n < 0)
		len += 1;
	a = ft_strnew(len);
	if (!a)
		return (a);
	i = 0;
	if (n < 0)
		a[i++] = 45;
	ft_digits(a, num, i, b);
	return (a);
}
