/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_framesetup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:35:41 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/10 17:35:41 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"

t_wire		*ft_framesetup(t_matrix *m)
{
	t_wire	*frame;

	frame = (t_wire*)ft_memalloc(sizeof(t_wire));
	if (!frame)
		return (NULL);
	frame->angle = (int*)ft_memalloc(sizeof(int) * 3);
	if (!(frame->angle))
	{
		ft_memdel((void**)&frame);
		return (NULL);
	}
	frame->po = ft_3dpoints(m, 0, 0);
	frame->l = m->l;
	frame->pl = m->pl;
	frame->xo = 0;
	frame->yo = 0;
	frame->zoom = 10;
	return (frame);
}
