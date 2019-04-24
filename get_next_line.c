/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:57:32 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/24 17:45:22 by tkarri           ###   ########.fr       */
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
		return (root = create_root(root, fd));
	else
		return (aedd_list_el(root, fd));
}

int		is_any_line(s_list *current, char **line)//0 - no; -1 - error; 1 - ok;
{
	char *first_n;

	if (current->line != NULL && (first_n = ft_strchr(current->line, '\n')) != NULL)
	{
		if ((*line = (char *)malloc(ft_strlen(first_n) + 1)) == NULL)
			return (-1);
		*first_n = '\0';
		first_n++;
		ft_strcpy(*line, current->line);
		first_n = ft_strdup(first_n);
		free(current->line);
		current->line = first_n;
		free(first_n);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static s_list	*root;
	s_list			*current;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	if ((current = get_current_el(fd, root)) == NULL)
		return (-1);
	if ((ret = is_any_line(current, line)) == 0)
	{
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
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 || is_any_line(current, line) == 0)
		return (0);
	return (0);
}
