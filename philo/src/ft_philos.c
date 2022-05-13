/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:44:11 by azabir            #+#    #+#             */
/*   Updated: 2022/04/21 12:44:13 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philos(t_philo *phi)
{
	int				j;
	struct timeval	time;

	phi->philos = malloc(sizeof(t_philosopher) * phi->nof);
	phi->fork = malloc(sizeof(pthread_mutex_t) * phi->nof);
	pthread_mutex_init(&(phi->print), NULL);
	j = 1;
	while (j <= phi->nof)
	{
		pthread_mutex_init(&(phi->fork)[j - 1], NULL);
		phi->philos[j - 1].lte = time_now();
		j++;
	}
	gettimeofday(&time, NULL);
	phi->inittime = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	phi->philos_done = 0;
	phi->all_alive = 1;
}
