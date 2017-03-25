/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:48:27 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/04 13:16:46 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s;
	unsigned char *s0;

	s = (unsigned char *)s1;
	s0 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*s == *s0)
		{
			s++;
			s0++;
		}
		else
			return (*s - *s0);
		--n;
	}
	return (0);
}
