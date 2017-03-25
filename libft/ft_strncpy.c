/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:19:05 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/11 19:08:06 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *tmp;

	tmp = dst;
	while (len > 0 && *src)
	{
		*tmp++ = *src++;
		--len;
	}
	while (len > 0 && *tmp)
	{
		*tmp++ = '\0';
		--len;
	}
	return (dst);
}
