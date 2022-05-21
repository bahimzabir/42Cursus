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
		print_time(th, id, "has taking a fork");
		sem_wait((th->proce));
		print_time(th, id, "has taking a fork");
		th->last_meal = time_now();
		print_time(th, id, "\033[0;32mis eating\033[0m");
		ft_msleep(th->tte);
		eat_times++;
		print_time(th, id, "is sleeping");
		sem_post((th->proce));
		sem_post((th->proce));
		ft_msleep (th->tts);
		usleep (50);
	}
	exit(0);
	sem_close(th->proce);
}

void	threads_handler(t_philo *data)
{
	int	j;

	j = 1;
	sem_unlink("proce");
	data->proce = sem_open("proce", O_CREAT, 0677, data->nof);
	sem_unlink("print_pause");
	data->print_pause = sem_open("print_pause", O_CREAT, 0677, 1);
	while (j <= data->nof)
	{
		(data->id) = j;
		data->pids[j - 1] = fork();
		if (data->pids[j - 1] == 0)
			ft_actions(data, j);
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
	data_init(&data);
	threads_handler(&data);
	waitpid(-1, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		kill_all(&data);
	if (data.tme > 1)
		while (wait(NULL) != -1)
		{
		}
	sem_unlink("proce");
	sem_close(data.print_pause);
	sem_close(data.proce);
	free (data.pids);
	sem_unlink("print_pause");
	return (0);
}
