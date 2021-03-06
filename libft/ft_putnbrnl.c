/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 22:54:42 by dhuang            #+#    #+#             */
/*   Updated: 2016/10/24 10:58:39 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

static void	ft_print(long num)
{
	char	c;

	if (num < 10)
	{
		c = num + 48;
		write(1, &c, 1);
		return ;
	}
	if (num >= 10)
		ft_print(num / 10);
	ft_print(num % 10);
}

void		ft_putnbrnl(int n)
{
	long	num;
	char	c;

	num = n;
	c = '-';
	if (num < 0)
	{
		write(1, &c, 1);
		num = num * -1;
	}
	ft_print(num);
	ft_putchar('\n');
}
