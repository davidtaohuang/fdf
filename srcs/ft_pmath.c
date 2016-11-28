/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pmath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 01:05:57 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/17 01:05:57 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../includes/fdf.h"

double	p2max(t_point **m, int a)
{
	double	max;

	max = (*m)->p[a];
	m++;
	while (*m)
	{
		if ((*m)->p[a] > max)
			max = (*m)->p[a];
		m++;
	}
	return (max);
}

double	p2min(t_point **m, int a)
{
	double	min;

	min = (*m)->p[a];
	m++;
	while (*m)
	{
		if ((*m)->p[a] < min)
			min = (*m)->p[a];
		m++;
	}
	return (min);
}
