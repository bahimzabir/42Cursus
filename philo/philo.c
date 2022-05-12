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
			print_lock(th, i, "is thinking");
		pthread_mutex_lock(&(th->fork)[th->philos[i - 1].id]);
		print_lock(th, i, "has taking a fork");
		pthread_mutex_lock(&(th->fork)[(th->philos[i - 1].id  + 1) % th->nof]);
		print_lock(th, i, "has taking a fork");
		print_lock(th, i, "is eating");
		th->philos[i].lte = time_now();
		usleep(th->tte * 1000);
		//ft_msleep(th->tte);
		th->philos[i].nte++;
		print_lock(th, i, "is sleeping");
		pthread_mutex_unlock(&(th->fork)[th->philos[i - 1].id]);
		pthread_mutex_unlock(&(th->fork)[(th->philos[i - 1].id  + 1) % th->nof]);
		usleep(th->tts * 1000);
		//ft_msleep (th->tts);
	}
	th->philos_done ++;
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
	health_check(data);
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
