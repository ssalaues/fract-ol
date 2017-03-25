/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:48:07 by ssalaues          #+#    #+#             */
/*   Updated: 2016/12/12 19:23:51 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin;

	if (!lst)
		return (NULL);
	new = ft_lstnew(lst->content, lst->content_size);
	new = f(lst);
	begin = new;
	while (lst->next != NULL)
	{
		new->next = f(lst->next);
		lst = lst->next;
		new = new->next;
	}
	return (begin);
}
