/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:48:01 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/09 17:38:54 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*tmp;
	int		len;
	int		ng;

	ng = 1;
	len = ft_intlen(n);
	tmp = ft_strnew(len + 1);
	if (!tmp)
		return (NULL);
	if (n < 0)
		ng = -1;
	while (len >= 0)
	{
		tmp[len--] = (ft_abs(n) % 10) + '0';
		n = ft_abs(n) / 10;
		if (len == 0 && ng < 0)
		{
			tmp[len] = '-';
			break ;
		}
	}
	return (tmp);
}
