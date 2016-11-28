/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:45:42 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/10 16:45:42 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "../includes/fdf.h"

#include <stdio.h>

int		ft_puterror(int i)
{
	if (i == 1)
		ft_putendl_fd("Invalid file.", 2);
	if (i == 2)
		ft_putendl_fd("Malloc error.", 2);
	return (i);
}

void	ft_putusage(void)
{
	ft_putendl_fd("Usage: ./fdf [projection type]", 2);
	ft_putendl_fd("Projection type: iso, parallel, or perspective", 2);
}

void	ft_switchboard(t_wire *f, int ac, char **av, int i)
{
	if (ac >= 3)
	{
		if (av[2])
		{
			i = 0;
			while (av[2][i])
				ft_tolower(av[2][i++]);
			ft_putendl("Calculating...");
			if (!ft_strcmp(av[2], "isometric"))
				ft_iso3d(f, f->po);
			else if (!ft_strcmp(av[2], "perspective"))
				ft_perspective3d(f, f->po);
			else
				ft_parallel3d(f, f->po);
		}
	}
	else
		ft_parallel3d(f, f->po);
	ft_translate(f->po);
	ft_scale(f, f->po, f->po);
}

int		main(int ac, char **av)
{
	t_matrix	*m;
	t_wire		*f;

	if (ac >= 2)
	{
		m = ft_getmap(av[1]);
		if (!m)
			return (ft_puterror(1));
		f = ft_framesetup(m);
		if (!f)
			return (ft_puterror(2));
		ft_switchboard(f, ac, av, 0);
		f->p = ft_cpypts(f, f->po);
		if (!(f->p))
		{
			ft_freefm(f, m);
			return (ft_puterror(2));
		}
		ft_freematrix(m, m->l);
		ft_mlxsetup(f, 0, 32, round(p2max(f->p, 0) + 1) * 4);
	}
	else
		ft_putusage();
	return (1);
}
