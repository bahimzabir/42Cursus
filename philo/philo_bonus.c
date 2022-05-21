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

/*void	print_time(t_philo *th,int id, char *action)
{
	if (th->all_alive)
	{
		printf ("\033[0;34m%ld \033[0m philo %d %s\n", timestamp(th),
			id, action);
	}
}*/

void	ft_actions(t_philo	*th, int id)
{
	int		eat_times;

	eat_times = 0;
	th->last_meal = time_now();
	pthread_create(&(th->health), NULL, proce_health, th);
	while (eat_times < th->tme && th->all_alive)
	{
		if (eat_times != 0 || id != 1)
			print_time(th, id, "is thinking");
		sem_wait((th->proce));
		sem_wait((th->proce));
		print_time(th, id, "has taking a fork");
		print_time(th, id, "has taking a fork");
		th->last_meal = time_now();
		print_time(th, id, "\033[0;32mis eating\033[0m");
		ft_msleep(th->tte);
		eat_times++;
		print_time(th, id, "is sleeping");
		sem_post((th->proce));
		sem_post((th->proce));
		ft_msleep (th->tts);
	}
	th->philos_done ++;
	exit(0);
	sem_close(th->proce);
}

void	threads_handler(t_philo *data)
{
	int	j;

	j = 1;
	sem_unlink("proce");
	data->proce = sem_open("proce", O_CREAT ,0677, data->nof);
	while (j <= data->nof)
	{
		data->index = malloc(sizeof(int));
		*(data->index) = j; 
		if (fork() == 0)
		{
			ft_actions(data, j);
		}
		j++;
	}
}

int	main(int arc, char **arv)
{
	t_philo	data;
	int		status;

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
	sem_unlink("proce");
	waitpid(-1, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		printf("Death detected\n");
	while (wait(NULL) != -1);
	return (0);
}
