/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:07:57 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/09 17:33:43 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	char	*str;
	char	*s1;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	s1 = (char *)s;
	str = ft_strnew(ft_strlen(s));
	tmp = str;
	if (!str)
		return (NULL);
	while (*s1)
	{
		*str = f(str - tmp, *s1);
		s1++;
		str++;
	}
	return (tmp);
}
