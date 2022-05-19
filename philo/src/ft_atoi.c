/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:18:57 by azabir            #+#    #+#             */
/*   Updated: 2022/04/19 10:19:00 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static long long int	ft_mknumber(char *s)
{
	long long int	r;

	r = 0;
	if (!*s)
		return (-1);
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (-1);
		r = (r * 10) + (*s - '0');
		if (r > 2147483647)
			return (-1);
		s++;
	}
	return (r);
}

int	ft_atoi(char *s, t_philo *data)
{
	int	i;
	int	j;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			return(-1);
		i++;
	}
	j = ft_mknumber((char *)s + i);
	if (j == -1)
		(*data).all_alive = 0;
	return (j);
}
