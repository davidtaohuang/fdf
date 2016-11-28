/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlxstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 23:42:37 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/02 22:49:39 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../includes/fdf.h"
#include "../includes/mlx.h"

void	ft_mlxinstructions(void)
{
	ft_putendl("Mouse hooks:\n");
	ft_putendl("Left-click = move center, drag image");
	ft_putendl("Right-click = drag image");
	ft_putendl("Scroll-wheel = translate image\n");
	ft_putendl("Key hooks:\n");
	ft_putendl("Arrow keys = translate image");
	ft_putendl("F = reset translation");
	ft_putendl("QWEASD = rotate image");
	ft_putendl("R = reset rotation");
	ft_putendl("Z = zoom in");
	ft_putendl("X = zoom out");
	ft_putendl("C = reset zoom");
}

void	ft_mlxprint(t_keydata d)
{
	unsigned int	i;
	unsigned int	xy;
	double			zmin;
	double			zrange;

	zmin = p2min(d.f->p, 2);
	zrange = p2max(d.f->p, 2) - p2min(d.f->p, 2);
	ft_putendl("Creating image...");
	i = 0;
	while (d.f->p[i])
	{
		d.f->po[i]->c = round((CR * (d.f->p[i]->p[2] - zmin)) / zrange) + CO;
		if (!(d.f->po[i]->c))
			d.f->po[i]->c = CO;
		xy = d.xmax * round(d.f->p[i]->p[1]) + round(d.f->p[i]->p[0]);
		*(d.imgd + xy) = mlx_get_color_value(d.mlx, d.f->po[i]->c);
		i++;
	}
	ft_makehedges(d, d.f->pl, d.f->l);
	ft_makevedges(d, d.f->pl, d.f->l);
	mlx_put_image_to_window(d.mlx, d.win, d.img, PXOFFSET, YOFFSET);
	ft_putendl("Done!");
	ft_mlxinstructions();
}

int		ft_mlxsetup(t_wire *f, int endian, int bbp, int line)
{
	t_keydata		d;

	d.f = f;
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, WINX, WINY, "fdf");
	d.oxmax = round(p2max(f->p, 0)) + 2;
	d.oymax = round(p2max(f->p, 1)) + 2;
	d.xmax = d.oxmax;
	d.ymax = d.oymax;
	d.img = mlx_new_image(d.mlx, d.xmax, d.ymax);
	d.bbp = bbp;
	d.line = line;
	d.endian = endian;
	d.mdown = 0;
	d.mbutton = 0;
	d.xp = 0;
	d.yp = 0;
	d.imgd = (unsigned int*)mlx_get_data_addr(d.img, &bbp, &line, &endian);
	ft_mlxprint(d);
	mlx_hook(d.win, 2, 1, ft_kdown, (void*)&d);
	mlx_hook(d.win, 6, 1, ft_drag, (void*)&d);
	mlx_hook(d.win, 5, 1, ft_mouseup, (void*)&d);
	mlx_hook(d.win, 4, 1, ft_mousedown, (void*)&d);
	mlx_loop(d.mlx);
	return (1);
}
