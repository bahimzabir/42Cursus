/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:48:21 by azabir            #+#    #+#             */
/*   Updated: 2022/04/18 20:48:23 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
#make actions time more realistic
#add time to die
#add bomus
*/

void	*ft_actions(void	*arg)
{
	t_philo	*th;
	int		i;

	th = (t_philo *)arg;
	i = *(th->index);
	while (th->philos[i].nte < th->tme)
	{
		if (i != 0 || th->philos[i].nte != 0)
			print_lock(th, i, "is thinking");
		pthread_mutex_lock(&(th->fork)[th->philos[i].id - 1]);
		print_lock(th, i, "has taking left fork");
		pthread_mutex_lock(&(th->fork)[(th->philos[i].id) % th->nof]);
		print_lock(th, i, "has taking right fork");
		th->philos[i].lte = time_now();
		print_lock(th, i, "is eating");
		ft_msleep(th->tte);
		th->philos[i].nte++;
		print_lock(th, i, "is sleeping");
		pthread_mutex_unlock(&(th->fork)[(th->philos[i].id) % th->nof]);
		pthread_mutex_unlock(&(th->fork)[th->philos[i].id - 1]);
		ft_msleep (th->tts);
	}
	th->philos_done ++;
	return (NULL);
}

void	threads_handler(t_philo *data)
{
	int	j;

	j = 1;
	pthread_create(&(data->health), NULL, health_check, data);
	while (j <= data->nof)
	{
		data->index = malloc(sizeof(int));
		*(data->index) = j - 1;
		data->philos[j - 1].id = j;
		data->philos[j - 1].nte = 0;
		pthread_create(&(data->philos[j - 1].philo), NULL, ft_actions, data);
		usleep(10);
		j++;
	}
	j = 1;
	while (j <= data->nof)
	{
		data->philos[j - 1].id = j;
		pthread_join((data->philos[j - 1].philo), NULL);
		j++;
		usleep(10);
	}
}

int	main(int arc, char **arv)
{
	t_philo	data;

	if (arc != 6 && arc != 5)
		ft_exit();
	fill_data(&data, arv);
	ft_philos(&data);
	threads_handler(&data);
}
