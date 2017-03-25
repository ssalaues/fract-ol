/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:32:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/02/13 21:39:04 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl		*gnl_lstnew(t_gnl *bl, size_t len, int fd)
{
	t_gnl			*new;

	if (!bl)
	{
		new = (t_gnl *)malloc(sizeof(t_gnl));
		new->data = (char *)ft_memalloc(sizeof(char));
		ft_bzero(new->t1, BUFF_SIZE + 1);
		new->fd = fd;
		new->next = NULL;
		bl = new;
		return (new);
	}
	if (bl && bl->fd != fd)
		bl->next = gnl_lstnew(bl->next, len, fd);
	new = bl;
	while (new)
	{
		if (new->fd == fd)
			return (new);
		new = new->next;
	}
	return (bl);
}

static int			line_cp(t_gnl *bl, char **line)
{
	bl->t2 = bl->data;
	*line = ft_strndup(bl->data, ft_wordlen(bl->data, '\n'));
	if ((bl->data = ft_strchr(bl->data, '\n')))
		bl->data++;
	if (bl->data)
	{
		bl->data = ft_strdup(bl->data);
		ft_strdel(&bl->t2);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*bl;

	if (!bl || bl->fd != fd)
		bl = gnl_lstnew(bl, BUFF_SIZE + 1, fd);
	while ((bl->bs = read(fd, bl->t1, BUFF_SIZE)) || bl->data != 0)
	{
		if (!*bl->t1 && bl->bs < 0)
			return (-1);
		if (*bl->t1)
		{
			bl->t2 = bl->data;
			bl->data = ft_strjoin(bl->data, bl->t1);
			if (bl->t2)
				ft_strdel(&bl->t2);
		}
		ft_bzero(bl->t1, BUFF_SIZE + 1);
		if ((!bl->bs && *bl->data != '\0') || (ft_strchr(bl->data, '\n')))
			return (line_cp(bl, line));
		if (bl->bs == 0)
			return (0);
	}
	return (0);
}
