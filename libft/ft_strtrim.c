/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:41:02 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/12 19:20:29 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i1;
	size_t	i2;

	if (!s)
		return (NULL);
	i1 = 0;
	i2 = ft_strlen(s) - 1;
	while (s[i1] == ' ' || s[i1] == '\n' || s[i1] == '\t')
		i1++;
	while (i2 > 0 && (s[i2] == ' ' || s[i2] == '\n' || s[i2] == '\t'))
		i2--;
	if (i2 < i1)
	{
		if (!(str = (char *)malloc(1)))
			return (NULL);
		*str = '\0';
		return (str);
	}
	str = ft_strsub(s, i1, i2 - i1 + 1);
	if (!str)
		return (NULL);
	return (str);
}
