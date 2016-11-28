/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:47:13 by dhuang            #+#    #+#             */
/*   Updated: 2016/11/02 22:34:10 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"

static void	ft_ppl(t_matrix *matrix, char *old, char c)
{
	int		i;
	int		j;
	int		points;

	i = 0;
	j = 0;
	while (old[i])
	{
		points = 0;
		while (old[i] && old[i] != '\n')
		{
			if (old[i] != c && (old[i + 1] == '\n' || old[i + 1] == c ||
				old[i + 1] == '\0'))
				points++;
			i++;
		}
		matrix->ppl[j] = points;
		if (old[i] == '\n')
			i++;
		j++;
	}
}

static void	ft_makelines(t_matrix *array, char *old, char c)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (old[i])
	{
		if (old[i] == '\n')
		{
			y++;
			x = 0;
			i++;
		}
		else if (old[i] != c)
		{
			array->mat[y][x++] = ft_atoi(&old[i]);
			while (old[i] != c && old[i] != '\n' && old[i] != 0)
				i++;
		}
		while (old[i] == c)
			i++;
	}
}

t_matrix	*ft_matrix(char *str, char c, int lines)
{
	t_matrix	*array;
	int			i;

	if (!lines)
		return (0);
	array = (t_matrix*)ft_memalloc(sizeof(t_matrix));
	if (!array)
		return (array);
	array->l = lines;
	array->mat = (int**)ft_memalloc(sizeof(int*) * (lines + 1));
	array->ppl = (int*)ft_memalloc(sizeof(int) * lines);
	if (!(array->mat) || !(array->ppl))
		return (ft_freematrix(array, 0));
	ft_ppl(array, str, c);
	i = 0;
	while (i < lines)
	{
		array->mat[i] = (int*)ft_memalloc(sizeof(int) * (array->ppl[i]));
		if (!(array->mat[i++]))
			return (ft_freematrix(array, lines));
	}
	ft_makelines(array, str, c);
	array->pl = ft_max(array->ppl, array->l);
	return (array);
}
