/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:45:49 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/12 19:19:06 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;

	str = (char *)big;
	if (!*little || ft_strcmp(big, little) == 0)
		return (&(*(char *)big));
	while (*big != '\0' && len >= ft_strlen(little))
	{
		if (ft_strncmp(big, little, ft_strlen(little)) == 0)
			return (&(*(char *)big));
		big++;
		len--;
	}
	return (NULL);
}
