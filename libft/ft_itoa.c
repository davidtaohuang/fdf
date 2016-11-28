/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 22:39:27 by dhuang            #+#    #+#             */
/*   Updated: 2016/10/24 10:51:23 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static int	ft_length(long n)
{
	int		i;
	long	tens;

	i = 0;
	tens = 1;
	if (!n)
		i = 1;
	while (n >= tens)
	{
		tens *= 10;
		i++;
	}
	return (i);
}

static void	ft_digits(char *a, long num, int i)
{
	int		digits;
	int		c;
	long	tens;

	digits = ft_length(num);
	tens = 1;
	while (digits > 0)
	{
		tens *= 10;
		digits--;
	}
	while (tens >= 10)
	{
		tens /= 10;
		c = num / tens;
		a[i++] = (c + 48);
		num -= (c * tens);
	}
	a[i] = '\0';
}

char		*ft_itoa(int n)
{
	int		len;
	int		i;
	long	num;
	char	*a;

	num = (long)n;
	if (num < 0)
		num *= -1;
	len = ft_length(num);
	if (n < 0)
		len += 1;
	a = ft_strnew(len);
	if (!a)
		return (a);
	i = 0;
	if (n < 0)
		a[i++] = 45;
	ft_digits(a, num, i);
	return (a);
}
