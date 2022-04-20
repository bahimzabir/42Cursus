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

int *ft_philos(int	nof)
{
	int *i;
	int	j;

	i = malloc(sizeof(int) * nof);
	j = 0;
	while(j < nof)
	{
		i[j] = j + 1;
		j++;
	}
	return (i);
}

int *ft_forks(int	nof)
{
	int *i;
	int	j;

	i = malloc(sizeof(int) * nof);
	j = 0;
	while(j < nof)
	{
		i[j] = 1;
		j++;
	}
	return (i);
}

void	*ft_actions(void	*arg)
{
	t_philo	*temp;
	pthread_mutex_t mut;

	temp = (t_philo *)arg;
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
		i++;
	}
	i = 0;
	while (i < data->nof)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
}

void	fill_data(t_philo *data, char	**arv)
{
	int	i;

	i = 1;
	if (arv[i])
		(*data).nof = ft_atoi(arv[i]);
	i++;
	if (arv[i])
		(*data).ttd = ft_atoi(arv[i]);
	i++;
	if (arv[i])
		(*data).tte = ft_atoi(arv[i]);
	i++;
	if (arv[i])
		(*data).tts = ft_atoi(arv[i]);
	i++;
	if (arv[i])
		(*data).tme = ft_atoi(arv[i]);
	data->philos = ft_philos(data->nof);
	data->forks = ft_forks(data->nof);
}

int	main(int arc, char **arv)
{
	t_philo	data;
	if (arc != 6 && arc != 5)
		ft_exit();
	fill_data(&data, arv);
	threads_handler(&data);
}
