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

sem_t	*test;

void	print_time(t_philo *th,int id, char *action)
{
	if (th->all_alive)
	{
		printf ("\033[0;34m%ld \033[0m philo %d %s\n", timestamp(th),
			id, action);
	}
}

void	*ft_actions(void	*arg, int id)
{
	t_philo	*th;
	int		eat_times;
	int		last_meal;

	th = (t_philo *)arg;
	eat_times = 0;
	last_meal = time_now();
	while (eat_times < th->tme && th->all_alive)
	{
		if (eat_times != 0 || id != 1)
			print_time(th, id, "is thinking");
		sem_wait((test));
		sem_wait((test));
		print_time(th, id, "has taking left fork");
		print_time(th, id, "has taking right fork");
		print_time(th, id, "is eatting");
		ft_msleep(th->tte);
		eat_times++;
		print_time(th, id, "is sleeping");
		sem_post((test));
		sem_post((test));
		ft_msleep (th->tts);
	}
	th->philos_done ++;
	sem_close(th->proce);
	exit(0);
	return (NULL);
}

void	threads_handler(t_philo *data)
{
	int	j;

	j = 1;
	sem_unlink("test");
	test = sem_open("test", O_CREAT ,0677, data->nof);
	while (j <= data->nof)
	{
		if (fork() == 0)
		{
			ft_actions(data, j);
		}
		//usleep(500);
		j++;
	}
		wait(NULL);
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
	ft_philos(&data);
 	threads_handler(&data);
	/*while (data.all_alive && data.philos_done < data.nof)
	{
	}*/
	//free (data.fork);
	//free (data.philos);
	//system("leaks philo");
	sem_unlink("test");
	return (0);
}
