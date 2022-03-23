/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:34:18 by azabir            #+#    #+#             */
/*   Updated: 2022/03/22 10:34:22 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long int	ft_mknumber(char *s, int sign)
{
	long long int	r;

	r = 0;
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			exit (1);
		r = (r * 10) + (*s - '0');
		if (sign < 0 && r > 2147483649)
			return (0);
		else if (r > 2147483647 && sign > 0)
			return (-1);
		s++;
	}
	return (r);
}

int	ft_atoi(char *s)
{
	int	i;
	int sign;

	i = 0;
	sign = 1;
	if (s[i] == '-')
	{
		sign = -sign;
		i++;
	}
	return (sign * ft_mknumber((char *)s + i, sign));
}	