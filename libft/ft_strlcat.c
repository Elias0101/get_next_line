/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:43:47 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/12 15:54:15 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t ln1;
	size_t ln2;
	size_t i;

	ln1 = ft_strlen((const char*)dst);
	ln2 = ft_strlen(src);
	i = 0;
	while ((ln1 + i + 1 < size) && i < ln2)
	{
		dst[ln1 + i] = src[i];
		i++;
	}
	dst[ln1 + i] = '\0';
	if (size < ln1)
		return (size + ln2);
	return (ln1 + ln2);
}
