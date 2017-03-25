/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:52:34 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/12 17:07:07 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	char const	*s;
	size_t		size2;
	size_t		dsize;

	d = dst;
	s = src;
	size2 = size;
	while (*d != '\0' && size2-- != 0)
		d++;
	dsize = d - dst;
	if ((size2 = size - dsize) == 0)
		return (dsize + ft_strlen(s));
	while (*s != '\0')
	{
		if (size2 != 1)
		{
			*d++ = *s;
			size2--;
		}
		s++;
	}
	*d = '\0';
	return (dsize + (s - src));
}
