/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_khooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 00:32:41 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/24 00:32:41 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../includes/fdf.h"
#include "../includes/mlx.h"

void	ft_keyangles(int key, t_keydata *d)
{
	if (key == 13)
		d->f->angle[0] += -15;
	if (key == 1)
		d->f->angle[0] += 15;
	if (key == 0)
		d->f->angle[1] += -15;
	if (key == 2)
		d->f->angle[1] += 15;
	if (key == 12)
		d->f->angle[2] += 15;
	if (key == 14)
		d->f->angle[2] += -15;
	if (key == 15)
	{
		d->f->angle[0] = 0;
		d->f->angle[1] = 0;
		d->f->angle[2] = 0;
	}
	ft_mlxredraw(d);
}

void	ft_keytrans(int key, t_keydata *d)
{
	if (key == 126)
		d->f->yo -= 20;
	if (key == 125)
		d->f->yo += 20;
	if (key == 124)
		d->f->xo += 20;
	if (key == 123)
		d->f->xo -= 20;
	mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, d->img, DXO, DYO);
}

void	ft_keyexit(t_keydata *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	ft_freewire(d->f);
	exit(1);
}

int		ft_kdown(int key, t_keydata *d)
{
	if (key == 53)
		ft_keyexit(d);
	if ((key >= 0 && key <= 2) || (key <= 15 && key >= 12))
		ft_keyangles(key, d);
	if (key == 3 || (key >= 6 && key <= 8))
	{
		if (key == 3)
		{
			d->f->xo = 0;
			d->f->yo = 0;
		}
		if (key == 6)
			d->f->zoom++;
		if (key == 7)
			d->f->zoom--;
		if (key == 8)
			d->f->zoom = 10;
		ft_mlxredraw(d);
	}
	if (key <= 126 && key >= 123)
		ft_keytrans(key, d);
	return (0);
}
