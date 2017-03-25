/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:03:23 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/09 17:55:32 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	*min;

	nb = 0;
	min = "-2147483648";
	if (n == -2147483648)
		ft_putstr_fd(min, fd);
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n > 9 && n != -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n != -2147483648)
	{
		nb = n + '0';
		write(fd, &nb, 1);
	}
}