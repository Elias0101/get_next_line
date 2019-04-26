/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:58:56 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/26 17:10:20 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <libc.h>

# include "libft/libft.h"

# define BUFF_SIZE 32

typedef struct		s_link
{
	int				fd;
	char			*line;
	struct s_link	*next;
}					t_link;

int					is_any_line(t_link *current, char **line);

t_link				*get_curr(int fd, t_link *root);

int					is_correct(int fd, char **line, t_link **root,
		t_link **curr);

int					get_next_line(const int fd, char **line);

#endif
