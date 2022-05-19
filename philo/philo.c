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
	i = *(th->index);
	free(th->index);
	while (th->philos[i].nte < th->tme && th->all_alive)
	{
		if (i != 0 || th->philos[i].nte != 0)
			print_lock(th, i, "is thinking");
		pthread_mutex_lock(&(th->fork)[th->philos[i].id - 1]);
		print_lock(th, i, "has taking left fork");
		pthread_mutex_lock(&(th->fork)[(th->philos[i].id) % th->nof]);
		print_lock(th, i, "has taking right fork");
		th->philos[i].lte = time_now();
		print_lock(th, i, "\033[0;32mis eating\033[0m");
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
	while (j <= data->nof)
	{
		data->index = malloc(sizeof(int));
		*(data->index) = j - 1;
		data->philos[j - 1].id = j;
		data->philos[j - 1].nte = 0;
		pthread_create(&(data->philos[j - 1].philo), NULL, ft_actions, data);
		usleep(500);
		j++;
	}
}

int	main(int arc, char **arv)
{
	t_philo	data;

	if (arc != 6 && arc != 5)
		return(0);
	if (fill_data(&data, arv) == -1)
	{
		printf("Error\n");
		return(1);
	}
	ft_philos(&data);
	pthread_create(&(data.health), NULL, health_check, &data);
	threads_handler(&data);
	while (data.all_alive && data.philos_done < data.nof)
	{
	}
	free (data.fork);
	free (data.philos);
	system("leaks philo");
	return (0);
}
