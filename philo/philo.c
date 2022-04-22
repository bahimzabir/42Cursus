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
	t_philo	*temp;
	pthread_mutex_t lock;
	temp = (t_philo *)arg;
	pthread_mutex_init (&lock, NULL);
	printf("philo %d is eating\n", *(temp->philos));
	pthread_mutex_lock(&lock);
	(temp->philos)++;
	pthread_mutex_unlock(&lock);
	pthread_mutex_destroy(&lock);
	return (NULL);
}

void	threads_handler(t_philo *data)
{
	pthread_t	philo[(*data).nof];
	int			i;

	i = 0;
	while (i < data->nof)
	{
		pthread_create(&philo[i], NULL, &ft_actions, data);
		//(data->philos)++;
		i++;
	}
	i = 0;
	while (i < data->nof)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
}

int	main(int arc, char **arv)
{
	t_philo	data;
	if (arc != 6 && arc != 5)
		ft_exit();
	fill_data(&data, arv);
	threads_handler(&data);
}
