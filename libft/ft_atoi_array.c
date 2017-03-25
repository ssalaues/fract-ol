/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:10:35 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/15 14:49:52 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_atoi_array(const char * s)
{
	int	*ary;
	int	i;

	ary = (int*)ft_memalloc((ft_numct(s) * sizeof(int)) + 1);
	i = 1;
	while (*s)
	{
		if (ft_isdigit(*s) || *s == '-')
		{
			ary[i] = ft_atoi(s);
			i++;
		}
		s = ((ft_wordlen(s, ' ')) ? s + ft_wordlen(s, ' ') : s + 1);
	}
	ary[0] = i;
	return (ary);
}
