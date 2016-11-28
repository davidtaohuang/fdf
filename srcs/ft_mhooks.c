/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mhooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 00:44:05 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/24 00:44:05 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../includes/fdf.h"
#include "../includes/mlx.h"

int		ft_drag(int x, int y, t_keydata *d)
{
	if (d->mdown)
	{
		if (d->mbutton == 1 || d->mbutton == 2)
		{
			mlx_clear_window(d->mlx, d->win);
			d->f->xo += x - d->xp;
			d->f->yo += y - d->yp;
			d->xp = x;
			d->yp = y;
			mlx_put_image_to_window(d->mlx, d->win, d->img, DXO, DYO);
		}
	}
	return (0);
}

int		ft_mousedown(int button, int x, int y, t_keydata *d)
{
	d->xp = x;
	d->yp = y;
	d->mbutton = button;
	d->mdown = 1;
	if (button == 1)
	{
		d->f->xo = round((x - d->oxmax - OFFSET));
		d->f->yo = round((y - d->oymax - OFFSET));
	}
	if (button == 5)
		d->f->yo += 20;
	if (button == 4)
		d->f->yo -= 20;
	if (button == 6)
		d->f->xo += 20;
	if (button == 7)
		d->f->xo -= 20;
	mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, d->img, DXO, DYO);
	return (0);
}

int		ft_mouseup(int button, int x, int y, t_keydata *d)
{
	button = x + y;
	d->mbutton = 0;
	d->mdown = 0;
	return (0);
}
