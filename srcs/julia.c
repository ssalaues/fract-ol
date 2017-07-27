/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <ssalaues@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 14:13:40 by ssalaues          #+#    #+#             */
/*   Updated: 2017/06/24 14:13:42 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int jules(t_frac fr)
{
	fr.c_im = -0.7;
	fr.c_re = 0.27015;
	fr.x = 0;
	fr.row = 0;
	while(fr.row < fr.w)
	{
		fr.col = 0;
		while(fr.col < fr.h)
		{
			fr.x = 0;
			fr.y = 0;
			fr.iter = 0;
		}
		
	}
	return(0);
}
