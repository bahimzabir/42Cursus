/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azabir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:48:40 by azabir            #+#    #+#             */
/*   Updated: 2022/04/18 20:48:42 by azabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philosopher
{
	int				id;
	long			lte;
	int				nte;
	pthread_t		philo;
}	t_philosopher;

typedef struct s_philo
{
	int				nof;
	int				ttd;
	int				tte;
	int				tts;
	int				tme;
	int				*pids;
	int				id;
	long			last_meal;
	pthread_t		health;
	int				all_alive;
	int				philos_done;
	time_t			inittime;
	int				*index;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	sem_t			*proce;
	sem_t			*print_pause;
	t_philosopher	*philos;
	struct timeval	time;
}	t_philo;

long	time_now(void);
void	ft_msleep(int time);
int		*ft_forks(int nof);
void	kill_all(t_philo *data);
void	*health_check(void *ph);
time_t	timestamp(t_philo *phi);
void	ft_philos(t_philo *phi);
void	data_init(t_philo *data);
void	*proce_health(void	*arg);
int		ft_atoi(char *s, t_philo *data);
int		fill_data(t_philo *data, char	**arv);
void	print_time(t_philo *th, int id, char *action);
void	print_lock(t_philo	*th, int i, char *action);

#endif
