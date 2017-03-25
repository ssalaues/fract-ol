/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:02:25 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/11 20:00:37 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i2;
	char	*s;

	s = s1;
	i2 = ft_strlen(s2);
	if (n > i2)
		ft_strcat(s1, s2);
	else
	{
		while (*s1)
			s1++;
		ft_strncpy(s1, s2, n);
		while (n)
		{
			s1++;
			n--;
		}
		*s1 = '\0';
	}
	return (s);
}
