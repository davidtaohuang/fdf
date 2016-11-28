/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 22:58:17 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/10 22:58:17 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../includes/fdf.h"

void	ft_iso3d(t_wire *f, t_point **pts)
{
	t_point	**mtmp;
	double	x;
	double	y;
	double	z;

	ft_3drot(f->angle, pts);
	mtmp = pts;
	while (*mtmp)
	{
		x = (*mtmp)->p[0];
		y = (*mtmp)->p[1];
		z = (*mtmp)->p[2];
		(*mtmp)->p[0] = x * cosf(D2RAD(30)) - y * cosf(D2RAD(30));
		(*mtmp)->p[1] = x * sinf(D2RAD(30)) + y * sinf(D2RAD(30)) - z;
		mtmp++;
	}
}

void	ft_parallel3d(t_wire *f, t_point **pts)
{
	ft_3drot(f->angle, pts);
}
