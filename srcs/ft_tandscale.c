/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tandscale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:22:40 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/10 23:22:40 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../includes/fdf.h"

#define ZOOM f->zoom / 10

void	ft_translate(t_point **points)
{
	t_point	**tmp;
	double	min[2];

	min[0] = p2min(points, 0);
	min[1] = p2min(points, 1);
	tmp = points;
	while (*tmp)
	{
		(*tmp)->p[0] -= min[0];
		(*tmp)->p[1] -= min[1];
		tmp++;
	}
}

void	ft_scale(t_wire *f, t_point **pts, t_point **o)
{
	int		i;
	double	xscale;
	double	yscale;
	t_point	**mtmp;
	t_point	**otmp;

	i = 0;
	mtmp = pts;
	otmp = o;
	xscale = 2 * (p2max(otmp, 0));
	yscale = 2 * (p2max(otmp, 1));
	if (!xscale)
		xscale = 1;
	if (!yscale)
		yscale = 1;
	if (f->zoom <= 0)
		f->zoom = 1;
	while (mtmp[i])
	{
		(mtmp[i])->p[0] = mtmp[i]->p[0] / xscale * ZOOM * XMAX;
		(mtmp[i])->p[1] = mtmp[i]->p[1] / yscale * ZOOM * YMAX;
		i++;
	}
}

void	ft_transform(t_point *p, double *t)
{
	double	tmp[4];
	int		i;

	i = 0;
	while (i < 4)
	{
		tmp[i] = (t[i] * p->p[0]) + (t[i + 4] * p->p[1]) +
			(t[i + 8] * p->p[2]) + (t[i + 12] * p->p[3]);
		i++;
	}
	p->p[0] = (tmp[0] / tmp[3]);
	p->p[1] = (tmp[1] / tmp[3]);
	p->p[2] = (tmp[2] / tmp[3]);
	p->p[3] = 1;
}

double	*ft_transm(double *p, double *t)
{
	double	*tmp;
	int		i;
	int		j;

	tmp = (double*)ft_memalloc(sizeof(double) * 16);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 4)
		{
			tmp[j + i] = (t[j] * p[i]) + (t[j + 4] * p[i + 1]) +
				(t[j + 8] * p[i + 2]) + (t[j + 12] * p[i + 3]);
			j++;
		}
		i += 4;
	}
	ft_memdel((void**)&p);
	return (tmp);
}
