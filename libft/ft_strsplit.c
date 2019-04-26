/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:28:31 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/12 15:28:53 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <string.h>

#include "libft.h"

static	int		ft_count_words(char const *s, char c)
{
	int			i;
	int			count;
	int			in_word;

	in_word = 0;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (in_word == 0)
			{
				in_word = 1;
				count++;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}

static	int		find_beginning(char const *s, int i, int c)
{
	while (s[i] != '\0')
	{
		if (s[i] != c)
			return (i);
		i++;
	}
	return (i);
}

static	int		find_word(char const *s, int *start, int c)
{
	int			i;
	int			j;

	i = find_beginning(s, *start, c);
	*start = i;
	j = i;
	while (s[j] != c && s[j] != '\0')
		j++;
	return (j);
}

static	char	**free_memory(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		str[i] = NULL;
		i--;
	}
	free(str);
	str = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	int			count_words;
	char		**res;
	int			i;
	int			start;
	int			end;

	if (s == NULL)
		return (NULL);
	i = 0;
	start = 0;
	count_words = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (count_words + 1));
	if (res == NULL)
		return (NULL);
	while (i < count_words)
	{
		end = find_word(s, &start, c);
		if ((res[i++] = ft_strsub(s, (unsigned int)start,
						(size_t)(end - start))) == NULL)
			return (free_memory(res, i - 1));
		start = end;
	}
	res[i] = NULL;
	return (res);
}
