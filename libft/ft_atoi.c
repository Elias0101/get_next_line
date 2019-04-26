/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:03:30 by tkarri            #+#    #+#             */
/*   Updated: 2019/04/16 16:38:00 by tkarri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long double		res;
	long double		c;

	res = 0;
	sign = 1;
	i = 0;
	c = 9223372036854775807;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((str[i] == '+' || str[i] == '-') && ++i)
	{
		if (str[i - 1] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res * 10 + str[i] - '0' > c && sign > 0)
			return (-1);
		else if (res * 10 + str[i] - '0' > c + 1 && sign < 0)
			return (0);
		res = res * 10 + str[i++] - '0';
	}
	return ((int)(((long int)(res)) * sign));
}
