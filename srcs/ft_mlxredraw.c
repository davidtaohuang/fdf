/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlxredraw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:39:55 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/15 17:39:55 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../includes/fdf.h"
#include "../includes/mlx.h"

void	ft_mlxreprint(t_keydata *d)
{
	unsigned int	i;
	unsigned int	xy;

	mlx_destroy_image(d->mlx, d->img);
	d->xmax = round(p2max(d->f->p, 0) + 2);
	d->ymax = round(p2max(d->f->p, 1) + 2);
	d->img = mlx_new_image(d->mlx, d->xmax, d->ymax);
	d->imgd = (unsigned int*)mlx_get_data_addr(d->img,
		&(d->bbp), &(d->line), &(d->endian));
	i = 0;
	while (d->f->p[i])
	{
		xy = d->xmax * round(d->f->p[i]->p[1]) + round(d->f->p[i]->p[0]);
		*(d->imgd + xy) = mlx_get_color_value(d->mlx, d->f->po[i]->c);
		i++;
	}
	ft_makehedges(*d, d->f->pl, d->f->l);
	ft_makevedges(*d, d->f->pl, d->f->l);
	mlx_put_image_to_window(d->mlx, d->win, d->img, DXO, DYO);
}

void	ft_mlxredraw(t_keydata *d)
{
	mlx_clear_window(d->mlx, d->win);
	f_darray(d->f->p);
	d->f->p = ft_cpypts(d->f, d->f->po);
	ft_3drot(d->f->angle, d->f->p);
	ft_translate(d->f->p);
	ft_scale(d->f, d->f->p, d->f->po);
	ft_mlxreprint(d);
}
