/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perspective3D.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 00:17:13 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/11 00:17:13 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../includes/fdf.h"

double	*ft_w2csetup(double *c)
{
	double	*w2c;

	w2c = (double*)ft_memalloc(sizeof(double) * 16);
	if (!w2c)
		return (NULL);
	w2c[0] = 1;
	w2c[1] = 0;
	w2c[2] = 0;
	w2c[3] = 0;
	w2c[4] = 0;
	w2c[5] = 1;
	w2c[6] = 0;
	w2c[7] = 0;
	w2c[8] = 0;
	w2c[9] = 0;
	w2c[10] = 1;
	w2c[11] = 0;
	w2c[12] = c[0];
	w2c[13] = c[1];
	w2c[14] = c[2];
	w2c[15] = c[3];
	return (w2c);
}

double	*ft_w2c(t_wire *f)
{
	double	*w2c;
	double	*c;
	t_point	**mtmp;

	c = (double*)ft_memalloc(sizeof(double) * 16);
	if (!c)
		return (NULL);
	c[0] = round((double)(-0.5) * p2max(f->po, 0));
	c[1] = round((double)(-0.5) * p2max(f->po, 1));
	c[2] = -2 * p2max(f->po, 2);
	c[3] = 1;
	ft_3drot(f->angle, f->po);
	w2c = ft_w2csetup(c);
	mtmp = f->po;
	while (*mtmp)
	{
		ft_transform(*mtmp, w2c);
		mtmp++;
	}
	ft_memdel((void**)&c);
	return (w2c);
}

void	ft_2ddoubles(t_point **m)
{
	while (*m)
	{
		(*m)->p[0] = (*m)->p[0] / (*m)->p[2];
		(*m)->p[1] = (*m)->p[1] / (*m)->p[2];
		m++;
	}
}

void	ft_ss2r(t_point **m)
{
	double	width;
	double	height;
	t_point	**mtmp;

	mtmp = m;
	width = p2max(mtmp, 0) - p2min(mtmp, 0);
	height = p2max(mtmp, 1) - p2min(mtmp, 1);
	while (*mtmp)
	{
		(*mtmp)->p[0] = ((*mtmp)->p[0] + (width / 2)) / width;
		(*mtmp)->p[1] = ((*mtmp)->p[1] + (height / 2)) / height;
		mtmp++;
	}
}

void	ft_perspective3d(t_wire *f, t_point **pts)
{
	double	*w2c;
	t_point	**mtmp;

	w2c = ft_w2c(f);
	mtmp = pts;
	ft_2ddoubles(mtmp);
	ft_ss2r(mtmp);
	while (*mtmp)
	{
		(*mtmp)->p[0] = round((f->pl) * (1 - (*mtmp)->p[0]) *
			(XMAX / (double)f->pl));
		(*mtmp)->p[1] = round((f->l) * (1 - (*mtmp)->p[1]) *
			(YMAX / (double)f->l));
		mtmp++;
	}
	free(w2c);
}
