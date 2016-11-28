/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3dpoints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:31:47 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/02 22:30:15 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"

t_point	**ft_cpypts(t_wire *f, t_point **o)
{
	t_point	**tmp;
	int		i;

	tmp = (t_point**)ft_memalloc(sizeof(t_point*) * (FPTS));
	if (!tmp)
		return (NULL);
	i = 0;
	while (f->po[i])
	{
		tmp[i] = (t_point*)ft_memalloc(sizeof(t_point));
		if (!(tmp[i]))
			return (f_darray(tmp));
		(tmp[i])->p[0] = (o[i])->p[0];
		(tmp[i])->p[1] = (o[i])->p[1];
		(tmp[i])->p[2] = (o[i])->p[2];
		(tmp[i])->p[3] = (o[i])->p[3];
		i++;
	}
	return (tmp);
}

t_point	**ft_3dpoints(t_matrix *m, int i, int pi)
{
	t_point	**points;
	int		ppl;

	points = (t_point**)ft_memalloc(sizeof(t_point*) * (PTS));
	if (!points)
		return (NULL);
	while (i < m->l)
	{
		ppl = 0;
		while (ppl < m->pl)
		{
			points[pi] = (t_point*)ft_memalloc(sizeof(t_point));
			if (!(points[pi]))
				return (f_darray(points));
			(points[pi])->p[0] = ppl;
			(points[pi])->p[1] = i;
			(points[pi])->p[2] = m->mat[i][ppl++];
			(points[pi++])->p[3] = 1;
		}
		i++;
	}
	return (points);
}
