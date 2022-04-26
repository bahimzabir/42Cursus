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

void	*ft_actions(void	*arg)
{
	t_philo	*th;
	th = (t_philo *)arg;
	int	i;
	i = *(th->index);
while (1)
{
	printf ("philo %d is thinking\n", (th->philos[i].id));
	pthread_mutex_lock(&(th->fork)[th->philos[i].id]);
	printf ("philo %d has taking a fork\n", (th->philos[i].id));
	pthread_mutex_lock(&(th->fork)[(th->philos[i].id  + 1) % th->nof]);
	printf ("philo %d has taking a fork\n", (th->philos[i].id));
	printf ("philo %d is eating\n", (th->philos[i].id));
	sleep(1);
	pthread_mutex_unlock(&(th->fork)[th->philos[i].id]);
	pthread_mutex_unlock(&(th->fork)[(th->philos[i].id  + 1) % th->nof]);
	printf ("philo %d is sleeping\n", (th->philos[i].id));
	sleep (2);
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
		pthread_create(&(data->philos[j - 1].philo), NULL, ft_actions, data);
		usleep(20);
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
	int	j;
	t_philo	data;
	if (arc != 6 && arc != 5)
		ft_exit();
	fill_data(&data, arv);
	data.fork = malloc(sizeof(pthread_mutex_t) * data.nof);
	data.print = malloc(sizeof(pthread_mutex_t) * 2);
	data.philos = malloc (sizeof(t_philosopher) * data.nof);
	j = 1;
	while (j <= data.nof)
	{
		pthread_mutex_init(&(data.fork)[j - 1], NULL);
		j++;
	}
	pthread_mutex_init(&(data.print)[0], NULL);
	pthread_mutex_init(&(data.print)[1], NULL);
	threads_handler(&data);
}
