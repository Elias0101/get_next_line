/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:19:32 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/05 21:36:53 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *copy;

	copy = dst;
	while (*src != '\0')
	{
		if (len == 0)
			return (copy);
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	while (len > 0)
	{
		*dst = 0;
		dst++;
		len--;
	}
	return (copy);
}
