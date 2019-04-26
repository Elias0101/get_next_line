/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:05:10 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/12 18:49:34 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static	void	ft_reverse(char *str)
{
	int len;
	int i;
	int copy;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		copy = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = copy;
		i++;
	}
}

static	int		ft_intlen(long int n)
{
	int i;

	i = 0;
	if (n < 10)
		return (1);
	while ((n = n / 10) > 0)
		i++;
	return (i + 1);
}

static	void	fill_str(char *str, int len, long int n_copy, int *i)
{
	if (len == 1 && n_copy == 0)
		str[(*i)++] = n_copy + '0';
	while (n_copy > 0)
	{
		str[(*i)++] = n_copy % 10 + '0';
		n_copy = n_copy / 10;
	}
}

char			*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			is_minus;
	int			i;
	long int	n_copy;

	is_minus = 0;
	n_copy = n;
	i = 0;
	if (n_copy < 0)
	{
		is_minus = 1;
		n_copy *= (-1);
	}
	len = ft_intlen(n_copy);
	str = (char *)malloc(sizeof(char) * (len + 1 + is_minus));
	if (str == NULL)
		return (NULL);
	fill_str(str, len, n_copy, &i);
	if (is_minus)
		str[i++] = '-';
	str[i] = '\0';
	ft_reverse(str);
	return (str);
}
