/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:25:14 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/09 18:08:26 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c1;
	size_t	i;

	c1 = c;
	i = ft_strlen(s);
	if (!*s)
		return (NULL);
	while (s[i] != c1 && i > 0)
	{
		if (--i == 0 && s[i] != c1)
			return (NULL);
	}
	return ((&((char *)s)[i]));
}
