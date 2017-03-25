/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 20:47:43 by ssalaues          #+#    #+#             */
/*   Updated: 2017/01/25 16:11:22 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *dup;

	dup = ft_memalloc(n + 1);
	if (!dup)
		return (NULL);
	ft_strncpy(dup, s1, n);
	return (dup);
}
