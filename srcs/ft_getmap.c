/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:53:03 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/10 16:53:03 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "../includes/fdf.h"

int			ft_check_matrix(t_matrix *matrix)
{
	int			i;

	if (!(matrix->l))
		return (0);
	i = 0;
	while (i < matrix->l)
	{
		if (matrix->ppl[i++] != matrix->pl)
			return (0);
	}
	return (1);
}

t_matrix	*ft_getlines(int fd)
{
	int			i;
	char		*filebuf;
	char		nlbuf[1];
	char		*line;
	t_matrix	*matrix;

	filebuf = ft_strnew(0);
	nlbuf[0] = '\n';
	if (!(get_next_line(fd, &line)))
		return (NULL);
	filebuf = ft_strjoin(filebuf, line);
	ft_memdel((void**)&line);
	i = 1;
	while (get_next_line(fd, &line))
	{
		filebuf = ft_strjoin(filebuf, nlbuf);
		filebuf = ft_strjoin(filebuf, line);
		ft_memdel((void**)&line);
		i++;
	}
	matrix = ft_matrix(filebuf, ' ', i);
	if (ft_check_matrix(matrix))
		return (matrix);
	ft_freematrix(matrix, i);
	return (NULL);
}

t_matrix	*ft_getmap(char *str)
{
	int			fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	return (ft_getlines(fd));
}
