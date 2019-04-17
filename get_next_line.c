/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:57:32 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/17 21:02:35 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h> //allowed read maloc free

int		get_next_line(const int fd, char **line)
{
	static s_list	*root;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	if (root == NULL && (root = ft_create_root()) == NULL)
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
