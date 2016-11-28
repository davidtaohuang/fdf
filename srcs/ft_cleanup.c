/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:41:21 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/10 17:41:21 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"

t_point		**f_darray(t_point **array)
{
	t_point	**tmp;

	tmp = array;
	if (array)
	{
		while (*tmp)
		{
			ft_memdel((void**)(&(*tmp)));
			tmp++;
		}
		ft_memdel((void**)&array);
	}
	return (NULL);
}

t_matrix	*ft_freematrix(t_matrix *array, int lines)
{
	int		i;

	if (array)
	{
		if (array->mat)
		{
			i = 0;
			while (i < lines && array->mat[i])
				ft_memdel((void**)(&(array->mat[i++])));
			ft_memdel((void**)(&(array->mat)));
		}
		ft_memdel((void**)(&array));
	}
	return (NULL);
}

int			ft_freewire(t_wire *frame)
{
	if (frame->angle)
		ft_memdel((void**)(&(frame->angle)));
	f_darray(frame->p);
	f_darray(frame->po);
	ft_memdel((void**)&frame);
	return (0);
}

void		ft_freefm(t_wire *f, t_matrix *m)
{
	ft_freematrix(m, m->l);
	ft_freewire(f);
}
