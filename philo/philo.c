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
	int		i;
	th = (t_philo *)arg;
	i = *(th->philos.id);
while (1)
{
	pthread_mutex_lock(&(th->fork)[i]);
	printf ("philo %d is taking a fork\n", (i));
	pthread_mutex_lock(&(th->fork)[(i  + 1) % th->nof]);
	printf ("philo %d is taking a fork\n", (i));
	printf ("philo %d is eating\n", (i));
	usleep(th->tte * 1000);
	pthread_mutex_unlock(&(th->fork)[i]);
	pthread_mutex_unlock(&(th->fork)[(i  + 1) % th->nof]);
	printf ("philo %d is done\n", (i));
	usleep (th->tts * 1000);
}
	return(NULL);
}

void	threads_handler(t_philo *data)
{
	int	j;

	data->philos.philo = malloc(sizeof(t_thread) * data->nof);
	j = 1;
	while (j <= data->nof)
	{
		data->philos.id = malloc(sizeof(int));
		*(data->philos.id) = j;
		pthread_create(&(data->philos.philo[*(data->philos.id) - 1]), NULL, ft_actions, data);
		usleep(20);
		j++;
	}
	j = 1;
	while (j <= data->nof)
	{
		data->philos.id = malloc(sizeof(int));
		*(data->philos.id) = j;
		pthread_join((data->philos.philo[*(data->philos.id)]), NULL);
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
	j = 1;
	while (j <= data.nof)
	{
		pthread_mutex_init(&(data.fork)[j - 1], NULL);
		j++;
	}
	threads_handler(&data);
}
