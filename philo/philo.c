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
	th = (t_philo *)arg;
	int	i;
	i = *(th->index);
	while (th->philos[i].nte < th->tme)
	{
		if (i != 0 || th->philos[i].nte != 0)
			printf ("%ld: philo %d is thinking\n", timestamp(th), (th->philos[i].id));
		pthread_mutex_lock(&(th->fork)[th->philos[i].id]);
		printf ("%ld: philo %d has taking a fork\n", timestamp(th), (th->philos[i].id));
		pthread_mutex_lock(&(th->fork)[(th->philos[i].id  + 1) % th->nof]);
		printf ("%ld: philo %d has taking a fork\n", timestamp(th), (th->philos[i].id));
		printf ("%ld: philo %d is eating\n", timestamp(th), (th->philos[i].id));
		//usleep(th->tte * 1000);
		ft_msleep(th->tte);
		th->philos[i].nte++;
		printf ("%ld: philo %d is sleeping\n", timestamp(th), (th->philos[i].id));
		pthread_mutex_unlock(&(th->fork)[th->philos[i].id]);
		pthread_mutex_unlock(&(th->fork)[(th->philos[i].id  + 1) % th->nof]);
		//usleep(th->tts * 1000);
		ft_msleep (th->tts);
	}
	return(NULL);
}

void	threads_handler(t_philo *data)
{
	int	j;

	j = 1;
	while (j <= data->nof)
	{
		data->index = malloc(sizeof(int));
		*(data->index) = j - 1;
		data->philos[j - 1].id = j;
		data->philos[j - 1].nte = 0;
		pthread_create(&(data->philos[j - 1].philo), NULL, ft_actions, data);
		usleep(5);
		j++;
	}
	j = 1;
	while (j <= data->nof)
	{
		data->philos[j - 1].id = j;
		pthread_join((data->philos[j - 1].philo), NULL);
		j++;
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
