/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:24:15 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/12 17:53:18 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static	t_list	*free_all(t_list *root)
{
	t_list		*curr;

	while (root != NULL)
	{
		curr = root;
		root = root->next;
		free(curr);
		curr = NULL;
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*curr;
	t_list		*root;
	t_list		*new;

	root = NULL;
	if (!(lst && f))
		return (NULL);
	root = (t_list *)malloc(sizeof(t_list));
	if (root == NULL)
		return (NULL);
	root = f(lst);
	curr = root;
	lst = lst->next;
	while (lst)
	{
		if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (free_all(root));
		new = f(lst);
		curr->next = new;
		curr = curr->next;
		lst = lst->next;
	}
	return (root);
}
