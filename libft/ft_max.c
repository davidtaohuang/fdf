/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 23:11:20 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/01 16:02:35 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_max(int *n, size_t l)
{
	int		max;
	size_t	i;

	if (!n)
		return (0);
	max = *n;
	i = 1;
	while (i++ < l)
	{
		n++;
		if (*n > max)
			max = *n;
	}
	return (max);
}
