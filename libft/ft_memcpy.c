/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:38:22 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/12 15:53:09 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dt;
	const char	*sr;

	dt = dst;
	sr = src;
	while (n--)
	{
		*dt = *sr;
		dt++;
		sr++;
	}
	return ((void *)dst);
}
