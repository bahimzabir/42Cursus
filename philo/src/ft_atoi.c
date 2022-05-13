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

static long long int	ft_mknumber(char *s, t_philo *data)
{
	long long int	r;

	r = 0;
	if (!*s)
		ft_exit(1, data);
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			ft_exit(1, data);
		r = (r * 10) + (*s - '0');
		if (r > 2147483647)
			ft_exit(1, data);
		s++;
	}
	return (r);
}

int	ft_atoi(char *s, t_philo *data)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			ft_exit(1, data);
		i++;
	}
	return (ft_mknumber((char *)s + i, data));
}
