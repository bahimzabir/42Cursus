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
	int		eat_times;
	int		id;

	th = (t_philo *)arg;
	id = *(th->index);
	eat_times = 0;
	free(th->index);
	while (eat_times < th->tme && th->all_alive)
	{
		if (eat_times != 0 || id != 1)
			printf("philo %d is thinking\n", id);
		sem_wait((th->proce1));
		printf("philo %d has taking left fork\n", id);
		//write (1, "HERE\n", 5);
		sem_wait((th->proce1));
		printf("philo %d has taking right fork\n", id);
		//th->philos[i].lte = time_now();
		printf("philo %d is eating\n", id);
		ft_msleep(th->tte);
		eat_times++;
		printf("philo %d is sleeping\n", id);
		usleep(100);
		//sem_post((th->proce));
		//sem_post((th->proce));
		ft_msleep (th->tts);
	}
	th->philos_done ++;
	return (NULL);
}

void	threads_handler(t_philo *data)
{
	int	j;

	j = 1;
	data->proce1 = sem_open("semaphore", 0677, data->nof);
	while (j <= data->nof)
	{
		data->index = malloc(sizeof(int));
		*(data->index) = j;
		if (fork() != 0)
		{
			ft_actions(data);
		}
		usleep(500);
		j++;
	}
	sem_close(data->proce1);
}

int	main(int arc, char **arv)
{
	t_philo	data;

	if (arc != 6 && arc != 5)
		return (0);
	if (fill_data(&data, arv) == -1)
	{
		printf("Error\n");
		return (1);
	}
	//ft_philos(&data);
 	threads_handler(&data);
	/*while (data.all_alive && data.philos_done < data.nof)
	{
	}*/
	//free (data.fork);
	//free (data.philos);
	//system("leaks philo");
	sem_unlink("semaphore");
	return (0);
}
