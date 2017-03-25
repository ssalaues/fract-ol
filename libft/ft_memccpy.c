/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:26:10 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/09 18:14:41 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	unsigned char		c1;
	size_t				nb;

	d = dst;
	s = src;
	c1 = c;
	nb = 0;
	while (n > nb)
	{
		if (*s == c1)
		{
			nb++;
			ft_memcpy(dst, src, nb);
			return (&dst[nb]);
		}
		s++;
		nb++;
	}
	ft_memcpy(dst, src, nb);
	return (NULL);
}
