/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:07:14 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/12 19:08:49 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*str;

	if (s == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (ft_strsub(s, start, 0));
	while (end != -1 && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	if ((str = ft_strsub(s, start, end - start + 1)) == NULL)
		return (NULL);
	return (str);
}
