/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 11:49:14 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/22 14:15:39 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *b;

	b = *begin_list;
	while (b->next != 0)
	{
		if (!cmp(data_ref, b->data))
			free(b->data);
		b = b->next;
	}
	if (!cmp(data_ref, b->data))
		free(b->data);
}
