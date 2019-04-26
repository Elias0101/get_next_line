/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:41:23 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/16 20:02:18 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if (size == (size_t)(-1))
		return (NULL);
	new = (char *)ft_memalloc(size + 1);
	if (new)
	{
		ft_bzero((void *)new, size);
		return (new);
	}
	return (NULL);
}
