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
	int	*i;

	i = (int *)arg;

	printf ("philo %d doing something\n", *i);

	return(NULL);
}

void	threads_handler(t_philo *data)
{
	int	i;

	i = (int)malloc(sizeof(int));
	data->philos = malloc(sizeof(t_philo) * data->nof);
	i = 1;
	while (i <= data->nof)
	{
		pthread_create(&(data->philos[i - 1]), NULL, ft_actions, &i);
		i++;
	}
	i = 1;
	while (i <= data->nof)
	{
		pthread_join((data->philos[i - 1]), NULL);
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
