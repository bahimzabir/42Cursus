/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:30:51 by azabir            #+#    #+#             */
/*   Updated: 2022/05/15 17:30:53 by azabir           ###   ########.fr       */
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
		sem_wait((th->proce));
		print_lock(th, i, "has taking left fork");
		sem_wait((th->proce));
		print_lock(th, i, "has taking right fork");
		th->philos[i].lte = time_now();
		print_lock(th, i, "is eating");
		ft_msleep(th->tte);
		th->philos[i].nte++;
		print_lock(th, i, "is sleeping");
		sem_post((th->proce));
		sem_post((th->proce));
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
	data->proce = sem_open("sem_1", O_CREAT , 0644, data->nof);
	while (j <= data->nof)
	{
		data->index = malloc(sizeof(int));
		*(data->index) = j - 1;
		data->philos[j - 1].id = j;
		data->philos[j - 1].nte = 0;
		pthread_create(&(data->philos[j - 1].philo), NULL, ft_actions, data);
		usleep(300);
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
		ft_exit(1, &data);
	fill_data(&data, arv);
	ft_philos(&data);
	threads_handler(&data);
	ft_exit(0, &data);
}