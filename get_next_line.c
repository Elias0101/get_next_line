/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:57:32 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/22 20:38:43 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h> //allowed read maloc free

s_list	*create_root(s_list *root, int fd)//can be made with create el together
{
	if ((root = (s_list *)malloc(sizeof(s_list))) == NULL)
		return (NULL);
	root->fd = fd;
	root->line = NULL;
	root->next = NULL;
	return (root);
}

s_list	*add_list_el(s_list *root, int fd)
{
	s_list *tmp;

	tmp = root;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if ((tmp->next = (s_list *)malloc(sizeof(s_list))) == NULL)
		return (NULL);
	tmp = tmp->next;
	tmp->fd = fd;
	tmp->line = NULL;
	tmp->next = NULL;
	return (tmp);
}

s_list	*get_current_el(int fd, s_list *root) //file was used? //no - create corresponding el/create root
{
	if (root == NULL)
		return (create_root(root, fd));
	else
		return (aedd_list_el(root, fd));
}

int		get_next_line(const int fd, char **line)
{
	static s_list	*root;
	s_list			*current;
	char			buf[BUFF_SIZE + 1];
	//char			*tmp;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	if (root == NULL && (root = ft_create_root()) == NULL)
		return (-1);
	if ((current = get_current_el(fd, root)) == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (ft_memchr(
	}
}

int		main(void) //for testing
{
	return (0);
}
