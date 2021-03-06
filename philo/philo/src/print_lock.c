/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:49:28 by azabir            #+#    #+#             */
/*   Updated: 2022/05/12 17:49:33 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_lock(t_philo	*th, int i, char *action)
{
	usleep(100);
	if (th->all_alive)
	{
		pthread_mutex_lock(&th->print);
		printf ("%ld  philo %d %s\n", timestamp(th),
			(th->philos[i].id), action);
		pthread_mutex_unlock(&th->print);
	}
	else
		usleep(500000);
}
