/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edgepoints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:41:45 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/02 22:48:56 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../includes/fdf.h"
#include "../includes/mlx.h"

#define CB (int)d.f->po[b]->c
#define CA (int)d.f->po[a]->c
#define P0 (int)round(A[0] + (v[0] * t))
#define P1 (int)round(A[1] + (v[1] * t))
#define B d.f->p[b]->p
#define A d.f->p[a]->p

void	ft_edgepoints(int a, int b, t_keydata d)
{
	double			v[2];
	double			t;
	double			step;
	int				sp;

	v[0] = B[0] - A[0];
	v[1] = B[1] - A[1];
	sp = (fabs(v[0]) > fabs(v[1]) ? 0 : 1);
	step = 1 / fabs(v[sp]);
	t = step;
	while (t < 1)
	{
		*(d.imgd + (d.xmax * P1) + P0) = (CA == CB ? CA :
			round(t * (CB - CA) + CO));
		t += step;
	}
}

void	ft_makehedges(t_keydata d, int pl, int l)
{
	int		line;
	int		point;
	int		pi;
	int		ie;
	int		hedge[2];

	line = 0;
	ie = 0;
	point = 0;
	while (line < l)
	{
		pi = 0;
		while (pi++ < pl - 1)
		{
			hedge[0] = point++;
			hedge[1] = point;
			ft_edgepoints(hedge[0], hedge[1], d);
		}
		point++;
		line++;
	}
}

void	ft_makevedges(t_keydata d, int pl, int l)
{
	int		line;
	int		point;
	int		pi;
	int		ie;
	int		vedge[2];

	ie = 0;
	point = 0;
	while (point < pl)
	{
		pi = 0;
		line = point;
		while (pi++ < l - 1)
		{
			vedge[0] = line;
			line += pl;
			vedge[1] = line;
			ft_edgepoints(vedge[0], vedge[1], d);
		}
		point++;
	}
}
