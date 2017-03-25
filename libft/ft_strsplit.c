/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:40:29 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/22 14:01:57 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	nb;
	size_t	i;

	i = 0;
	if (!s || !c)
		return (NULL);
	nb = ft_wcount(s, c);
	str = (char **)malloc(sizeof(*str) * (nb + 1));
	if (!str)
		return (NULL);
	str[nb] = NULL;
	while (nb > 0)
	{
		while (*s == c && *s)
			s++;
		str[i] = ft_strsub(s, 0, ft_wordlen(s, c));
		s = s + ft_wordlen(s, c);
		i++;
		nb--;
	}
	return (str);
}
