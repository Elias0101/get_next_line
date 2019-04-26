/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:46:05 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/06 18:59:54 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		len_s1;
	int		len_s2;

	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		concat = (char *)malloc(sizeof(char) * (ft_strlen(s2) + len_s1 + 1));
		if (concat)
		{
			ft_strcpy(concat, s1);
			ft_strcpy(concat + len_s1, s2);
			return (concat);
		}
	}
	return (NULL);
}
