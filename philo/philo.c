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
	printf ("philo %d doing something\n", *(th->philos.id));
	return(NULL);
	free(th->philos.id);
}

void	threads_handler(t_philo *data)
{
	int	j;

	data->philos.philo = malloc(sizeof(pthread_t) * data->nof);
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
		pthread_join((data->philos.philo[*(data->philos.id) - 1]), NULL);
		j++;
	}
//	free((data->philos.id));
}

int	main(int arc, char **arv)
{
	t_philo	data;
	if (arc != 6 && arc != 5)
		ft_exit();
	fill_data(&data, arv);
	threads_handler(&data);
	data.fork = malloc(sizeof(pthread_mutex_t) * data.nof);
	free (data.philos.philo);
	while (1);
}
