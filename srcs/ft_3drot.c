/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3drot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 23:16:35 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/13 23:16:35 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../includes/fdf.h"

void	ft_xrot(double xr, t_point *p)
{
	double	y;
	double	z;

	y = p->p[1];
	z = p->p[2];
	p->p[1] = y * cosf(xr) + z * sinf(xr);
	p->p[2] = y * -sinf(xr) + z * cosf(xr);
}

void	ft_yrot(double yr, t_point *p)
{
	double	x;
	double	z;

	x = p->p[0];
	z = p->p[2];
	p->p[0] = z * sinf(yr) + x * cosf(yr);
	p->p[2] = z * cosf(yr) - x * sinf(yr);
}

void	ft_zrot(double zr, t_point *p)
{
	double	x;
	double	y;

	x = p->p[0];
	y = p->p[1];
	p->p[0] = x * cosf(zr) + y * sinf(zr);
	p->p[1] = -x * sinf(zr) + y * cosf(zr);
}

void	ft_3drot(int *angles, t_point **pts)
{
	double	xr;
	double	yr;
	double	zr;
	t_point	**tmp;
	int		i;

	xr = D2RAD(angles[0]);
	yr = D2RAD(angles[1]);
	zr = D2RAD(angles[2]);
	tmp = pts;
	i = 0;
	while (*tmp)
	{
		if (angles[0] % 360)
			ft_xrot(xr, *tmp);
		if (angles[1] % 360)
			ft_yrot(yr, *tmp);
		if (angles[2] % 360)
			ft_zrot(zr, *tmp);
		tmp++;
	}
}
