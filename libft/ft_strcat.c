/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 22:19:10 by dhuang            #+#    #+#             */
/*   Updated: 2016/09/28 14:38:00 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	char	*s;

	s = s1;
	while (*s)
		s++;
	while (*s2)
		*s++ = *s2++;
	*s = 0;
	return (s1);
}
