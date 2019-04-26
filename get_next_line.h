/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:58:56 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/26 16:03:24 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <libc.h>

# include "libft/libft.h"

# define BUFF_SIZE 32

typedef	struct	t_list
{
	int				fd;
	char			*line;
	struct t_list	*next;
}				s_list;

int					is_any_line(s_list *current, char **line);

s_list				*get_curr(int fd, s_list *root);

int					is_correct(int fd, char **line, s_list *root,
						s_list *curr);

int					get_next_line(const int fd, char **line);

#endif
