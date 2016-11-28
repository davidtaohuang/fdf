/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 15:35:41 by dhuang            #+#    #+#             */
/*   Updated: 2016/09/27 23:19:10 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char const *s)
{
	int		i;

	if (s)
	{
		i = 0;
		while (s[i])
			write(1, &s[i++], 1);
	}
}
