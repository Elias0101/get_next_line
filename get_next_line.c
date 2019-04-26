/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:57:32 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/26 16:02:10 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>

s_list	*get_curr(int fd, s_list *root)
{
	s_list *tmp;

	if (root == NULL)
	{
		if ((root = (s_list *)malloc(sizeof(s_list))) == NULL)
			return (NULL);
		root->fd = fd;
		root->line = NULL;
		root->next = NULL;
		return (root);
	}
	tmp = NULL;
	tmp = root;
	while (tmp->next != NULL && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp->fd == fd)
		return (tmp);
	if ((tmp->next = (s_list *)malloc(sizeof(s_list))) == NULL)
		return (NULL);
	tmp = tmp->next;
	tmp->fd = fd;
	tmp->line = NULL;
	tmp->next = NULL;
	return (tmp);
}

int		is_any_line(s_list *current, char **line)
{
	char	*tmp;
	int		len;

	len = 0;
	tmp = NULL;
	while ((current->line)[len] != '\0' && (current->line)[len] != '\n')
		len++;
	if ((current->line)[len] == '\n')
	{
		*line = ft_strsub(current->line, 0, len);
		tmp = ft_strdup(current->line + len + 1);
		free(current->line);
		current->line = tmp;
	}
	else if ((current->line)[len] == '\0')
	{
		*line = ft_strdup(current->line);
		ft_strdel(&(current->line));
	}
	return (1);
}

int		is_correct(int fd, char **line, s_list *root, s_list *curr)
{
	if (fd < 0 || line == NULL)
		return (0);
	if (root == NULL)
	{
		if ((root = get_curr(fd, root)) == NULL)
			return (0);
		curr = root;
	}
	else if ((curr = get_curr(fd, root)) == NULL)
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static s_list	*root;
	s_list			*curr;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	curr = NULL;
	if (is_correct(fd, line, root, curr) == 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (current->line == NULL)
			current->line = ft_strnew(1);
		tmp = ft_strjoin(current->line, buf);
		free(current->line);
		current->line = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (current->line == NULL || (current->line)[0] == '\0'))
		return (0);
	return (is_any_line(current, line));
}
